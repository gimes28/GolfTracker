#pragma once
#ifndef DATACLASS_h
#define DATACLASS_h

/*
* This class is the data set used to store in each node
* in the DataStructure class. It will contain the course name,
* the course par, the score the player got for that course, 
* the rating of the course, and the slope of the course.
*/

#include <iostream>
#include "Exception.h"

using namespace std;

class DataClass {
private: 
	string courseName;
	int coursePar;
	int playerScore;
	double courseRating;
	int courseSlope;
public:
	DataClass();
	DataClass(string name, int par, int score, double rating, int slope);

	void SetCourseName(string name);
	string GetCourseName();

	void SetCoursePar(int par);
	int GetCoursePar();

	void SetPlayerScore(int score);
	int GetPlayerScore();

	void SetCourseRating(double rating);
	double GetCourseRating();

	void SetCourseSlope(int slope);
	int GetCourseSlope();

	void Display();

	bool operator == (const DataClass&);
	bool operator < (const DataClass&);
	bool operator > (const DataClass&);
};

DataClass::DataClass() {
	courseName = "";
	coursePar = 0;
	playerScore = 0;
	courseSlope = 0;
	courseRating = 0;
}

DataClass::DataClass(string name, int par, int score, double rating, int slope) {
	courseName = name;
	coursePar = par;
	playerScore = score;
	courseRating = rating;
	courseSlope = slope;
}

void DataClass::SetCourseName(string name) {
	courseName = name;
}
string DataClass::GetCourseName() {
	return courseName;
}

void DataClass::SetCoursePar(int par) {
	coursePar = par;
}
int DataClass::GetCoursePar() {
	return coursePar;
}

void DataClass::SetPlayerScore(int score) {
	playerScore = score;
}
int DataClass::GetPlayerScore() {
	return playerScore;
}

void DataClass::SetCourseRating(double rating) {
	courseRating = rating;
}
double DataClass::GetCourseRating() {
	return courseRating;
}

void DataClass::SetCourseSlope(int slope) {
	courseSlope = slope;
}
int DataClass::GetCourseSlope() {
	return courseSlope;
}

void DataClass::Display() {
	cout << "============================" << "\n"
		<< "Course Name: " << courseName << "\n"
		<< "Par: " << coursePar << "\n"
		<< "Score: " << playerScore << "\n"
		<< "Rating/Slope: " << courseRating << "/" << courseSlope << "\n"
		<< "============================" << "\n";
}

bool DataClass::operator == (const DataClass& item) {
	return this->playerScore == item.playerScore;
}
bool DataClass::operator < (const DataClass& item) {
	return this->playerScore < item.playerScore;
}
bool DataClass::operator > (const DataClass& item) {
	return this->playerScore > item.playerScore;
}

#endif

