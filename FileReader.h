#pragma once
#ifndef FILEREADER_h
#define FILEREADER_h

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DataClass.h"

using namespace std;

class FileReader {
private:
	string line;
	const string SPACE = " ";
public:
	void ReadFile(string file);
};

void FileReader::ReadFile(string file) {
	string word;
	ifstream inputFile;
	bool tempBool = true;
	DataClass *roundInfo = new DataClass;

	inputFile.open(file, ios::in);

	while (inputFile >> word) {
		getline(inputFile, line);
		int lastNamePos = line.find(',');
		roundInfo->SetCourseName(line.substr(1, lastNamePos - 1));
		line = line.substr(lastNamePos + 6);
		int lastParPos = line.find(',');
		roundInfo->SetCoursePar(stoi(line.substr(1, lastParPos - 1)));
		line = line.substr(lastParPos + 8);
		int lastScorePos = line.find(',');
		roundInfo->SetPlayerScore(stoi(line.substr(1, lastScorePos - 1)));
		line = line.substr(lastScorePos + 9);
		int lastRatingPos = line.find(',');
		roundInfo->SetCourseRating(stod(line.substr(1, lastRatingPos - 1)));
		line = line.substr(lastRatingPos + 8);
		int lastSlopePos = line.find(',');
		roundInfo->SetCourseSlope(stoi(line.substr(1, lastSlopePos - 1)));
	}
}

#endif