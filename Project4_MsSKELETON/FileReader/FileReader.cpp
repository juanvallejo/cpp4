#include <iostream>
#include <fstream>
#include "../Include/FileReader.h"
#include "../Include/constants.h"
#include "../Include/Debug_Help.h"
using namespace std;
using namespace KP_FileReaderClass;

// define constructor and destructor
KP_FileReaderClass::FileReader::FileReader() {}
KP_FileReaderClass::FileReader::~FileReader() {}

//TODO Fill this in
int KP_FileReaderClass::FileReader::getFileContents(const std::string filename, std::string& contents) {
	
	this->filecontents = contents;
	std::ifstream file(filename);

	if(!file) {
		std::cout << "File (" << filename << ") missing... (Check spelling?)" << std::endl;
		std::cout << ENTER_FN_OR_X << std::endl;

		char input_stream[100];
		std::cin >> input_stream;

		if(input_stream != EXITCHAR) {
			this->getFileContents(std::string(input_stream), contents);
		} else {
			exit(USER_CHOSE_TO_EXIT);
		}

	} else {
		this->ReadTheWholeFile(filename);
		contents = this->filecontents;
	}

	return 0;
}

int KP_FileReaderClass::FileReader::ReadTheWholeFile(const std::string& filename) {

	std::ifstream file(filename);
	std::string line;

	for(;std::getline(file, line);) {

		// ignore any empty lines
		if(line.length() > 0) {

			// add line endings to each line
			line += '\n';

			this->filecontents += line;
		}

	}

	return 0;
}