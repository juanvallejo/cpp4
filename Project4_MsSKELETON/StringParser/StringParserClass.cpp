
#include <string>
#include "../Include/StringParserClass.h"
#include "../Include/FileReader.h"
#include "../Include/constants.h"
#include "../Include/Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

//TODO Fill this in
KP_StringParserClass::StringParserClass::StringParserClass() {

}

KP_StringParserClass::StringParserClass::~StringParserClass() {

}

int KP_StringParserClass::StringParserClass::getLastError() {
	if(!this->lastError) {
		this->lastError = 0;
	}
	return this->lastError;
}

bool KP_StringParserClass::StringParserClass::setTags(const char* pStartTag, const char* pEndTag) {
	this->pStartTag = (char *)pStartTag;
	this->pEndTag = (char *)pEndTag;
	this->areTagsSet = true;
	return true;
}

bool KP_StringParserClass::StringParserClass::getDataBetweenTags(char* pDataToSearchThru, vector<std::string>& myVector) {

	if(!this->areTagsSet) {
		std::cout << "ERR" << "Please set tags to match before attempting to parse a file." << std::endl;
		return 0;
	}

	char* line = (char *)malloc(sizeof(char) * 1000);
	int lineIndex = 0;

	char* lFirstChar = (char *)malloc(sizeof(char));
	char* lLastChar = (char *)malloc(sizeof(char));

	for(int i = 0; i < strlen(pDataToSearchThru) + 1; i++) {
		if(pDataToSearchThru[i] != '\n') {
			line[lineIndex] = pDataToSearchThru[i];
			lineIndex++;

		} else {
			
			lFirstChar = &line[0];
			lLastChar = &line[strlen(line) - 1];

			// only save the string if the tag we're looking for
			// is contained within the current string
			if(this->findTag(this->pStartTag, lFirstChar, lLastChar) && this->findTag(this->pEndTag, lFirstChar, lLastChar)) {
				myVector.push_back(std::string(line));
			}

			lineIndex = 0;
			memset(line, 0, strlen(line));
		}
	}

	lFirstChar = &line[0];
	lLastChar = &line[strlen(line) - 1];

	if(strlen(line) > 0 && this->findTag(this->pStartTag, lFirstChar, lLastChar) && this->findTag(this->pEndTag, lFirstChar, lLastChar)) {
		myVector.push_back(line);
	}

	return true;
}

bool KP_StringParserClass::StringParserClass::findTag(char* pTagToLookFor, char*& pStart, char*& pEnd) {

	char* iterator = pStart;
	bool match_started = false;
	bool match_found = false;
	int match_iter = 0;

	while(iterator != pEnd) {

		if(!match_started && *iterator == pTagToLookFor[match_iter] && (*(iterator + 1) != '\0') && *(iterator + 1) == pTagToLookFor[match_iter + 1]) {
			match_started = true;

			match_iter++;

			if((match_iter + 1) == strlen(pTagToLookFor)) {
				match_found = true;
			}

		} else if(match_started && (*(iterator) + 1) != '\0' && *(iterator + 1) == pTagToLookFor[++match_iter]) {
			if((match_iter + 1) == strlen(pTagToLookFor)) {
				match_found = true;
				match_started = false;
				match_iter = 0;
			}
		} else if(match_started) {
			match_started = false;
			match_iter = 0;
		}

		iterator++;
	}

	return match_found;
}