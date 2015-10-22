OBJECTS=FileReader.o StringParserClass.o StringParser_TEST.o
CXX=g++
IFLAGS= -I ./Project4_MsSKELETON
DEBUG= -g
CFLAGS= -Wall -c
LFLAGS= -Wall $(DEBUG) $(INCLUDE)
PROJECT= Project4

all: $(OBJECTS) 
	$(CXX) $(LFLAGS) $(OBJECTS) -o $(PROJECT); if [[ ! -d build ]]; then mkdir build; fi; mv *.o build; mv $(PROJECT) build

FileReader.o: Project4_MsSKELETON/FileReader/FileReader.cpp Project4_MsSKELETON/Include/FileReader.h Project4_MsSKELETON/Include/constants.h Project4_MsSKELETON/Include/Debug_Help.h
	$(CXX) $(CFLAGS) Project4_MsSKELETON/FileReader/FileReader.cpp $(IFLAGS)

StringParser_TEST.o: Project4_MsSKELETON/StringParser/StringParserClass.cpp Project4_MsSKELETON/StringParser_TEST/StringParser_TEST.cpp Project4_MsSKELETON/Include/FileReader.h Project4_MsSKELETON/Include/constants.h Project4_MsSKELETON/Include/Debug_Help.h Project4_MsSKELETON/Include/StringParserClass.h
	$(CXX) $(CFLAGS) Project4_MsSKELETON/StringParser_TEST/StringParser_TEST.cpp $(IFLAGS)

StringParserClass.o: Project4_MsSKELETON/StringParser/StringParserClass.cpp Project4_MsSKELETON/Include/FileReader.h Project4_MsSKELETON/Include/constants.h Project4_MsSKELETON/Include/Debug_Help.h Project4_MsSKELETON/Include/StringParserClass.h
	$(CXX) $(CFLAGS) Project4_MsSKELETON/StringParser/StringParserClass.cpp $(IFLAGS)

clean:
	if [[ -d build ]]; then rm -rf build; else rm -f *.o; rm -f $(PROJECT); fi; if [[ -f OutputStrings.txt ]]; then rm OutputStrings.txt; fi

run:
	if [[ -d build ]] && [[ -f build/$(PROJECT) ]]; then sh -c "./build/$(PROJECT)"; fi