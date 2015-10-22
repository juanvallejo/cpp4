/**
 * Proj4_Test.cpp
 * @juanvallejo
 * v1.0
 * Hello Worls in C++, Ansi-style
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "../Include/FileReader.h"	//relative path, from PWD, go up one, then down into Include to find FileReader.h
#include "../Include/constants.h"
#include "../Include/Debug_Help.h"
#include "../Include/StringParserClass.h"

void outputvectorrow(std::string i){
	std::cout<<i<<std::endl;
}
void foreach(std::vector<std::string> myVector){
	std::for_each(myVector.begin(), myVector.end(), outputvectorrow);
}

int main() {

	//TODO open file, if not there ask for a different file or exit
	std::string contents;

	KP_FileReaderClass::FileReader fileReader;
	int frStatus = fileReader.getFileContents(TEST_FILE_NAME, contents);
	if(frStatus != SUCCEEDED) {
		return frStatus;
	}

	//got file data, this is a bogus time and memory wasting step
	//whose sole purpose is to provide a way to pass
	//in a non const pointer to getDataBetweenTags(..) without casting
	/*vector<char> myLine;
	std::copy(filecontents.begin(), filecontents.end(), back_inserter(myLine));*/

	//TODO  create an instance of the stringparser
	KP_StringParserClass::StringParserClass stringParser;

	//TODO set the tags
	if(!stringParser.setTags(START_TAG, END_TAG)) {
		return stringParser.getLastError();
	}

	//TODO pull out the data
	std::vector<std::string> strings;
	const char* f_contents = contents.c_str();
	
	if(!stringParser.getDataBetweenTags((char *)f_contents, strings)) {
		return stringParser.getLastError();
	}

	//TODO  write to file and to screen

	std::ofstream file(OUTPUTFILENAME);

	if(!file) {
		return COULD_NOT_WRITE_CONTAINER_TO_FILE;
	}

	for(int i = 0; i < strings.size(); i++) {

		std::cout << strings.at(i) << std::endl;
		file << strings.at(i) << std::endl;

	}

	return SUCCEEDED;

}



