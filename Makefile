OBJECTS=FileReader.o StringParserClass.o StringParser_TEST.o
CXX=g++
IFLAGS= -I ./Project4_MsSKELETON
DEBUG= -g
CFLAGS= -Wall -c
LFLAGS= -Wall $(DEBUG) $(INCLUDE)

all: $(OBJECTS)
	$(CXX) $(LFLAGS) $(OBJECTS) -o Project4

FileReader.o: Project4_MsSKELETON/FileReader/FileReader.cpp Project4_MsSKELETON/Include/FileReader.h Project4_MsSKELETON/Include/constants.h Project4_MsSKELETON/Include/Debug_Help.h
	$(CXX) $(CFLAGS) Project4_MsSKELETON/FileReader/FileReader.cpp $(IFLAGS)

StringParser_TEST.o: Project4_MsSKELETON/StringParser/StringParserClass.cpp Project4_MsSKELETON/StringParser_TEST/StringParser_TEST.cpp Project4_MsSKELETON/Include/FileReader.h Project4_MsSKELETON/Include/constants.h Project4_MsSKELETON/Include/Debug_Help.h Project4_MsSKELETON/Include/StringParserClass.h
	$(CXX) $(CFLAGS) Project4_MsSKELETON/StringParser_TEST/StringParser_TEST.cpp $(IFLAGS)

StringParserClass.o: Project4_MsSKELETON/StringParser/StringParserClass.cpp Project4_MsSKELETON/Include/FileReader.h Project4_MsSKELETON/Include/constants.h Project4_MsSKELETON/Include/Debug_Help.h Project4_MsSKELETON/Include/StringParserClass.h
	$(CXX) $(CFLAGS) Project4_MsSKELETON/StringParser/StringParserClass.cpp $(IFLAGS)