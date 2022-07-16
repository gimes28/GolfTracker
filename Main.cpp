#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DataClass.h"
#include "LinkedList.h"
#include "Exception.h"

/*
* The main.cpp includes a main(), readFile(), 
* scoreDifferetial(), and Menu() functions. main() has all
* of the executable code allowing the user to input there 
* option and performing the calls to the linkedList class. 
* readFile() simply reads and breaks down the .txt file, then
* calls members from the DataClass class, then creates a new
* node to put into the LinkedList class. scoreDifferential() 
* is used for calculating the handicap. Menu() simply displays
* the options the user has while the while loop is running  
*/

using namespace std;

void Menu() {
	cout << "Option 1: Display handicap\n";
	cout << "Option 2: Display list of rounds\n";
	cout << "Option 3: Display list of course names\n";
	cout << "Option 4: Display lowest scoring round\n";
	cout << "Option 5: Display highest scoring round\n";
	cout << "Option 6: Display easiest course\n";
	cout << "Option 7: Display hardest couse\n";
	cout << "Option 8: Quit\n";
}

void ReadFile(string file, LinkedList<DataClass> &list) {
	// MUST USE FORMAT FROM txt file
	// FORMAT - Name: "course name", Par: "course par", Score: "player score", Rating: "course rating", Slope: "course slope"
	string word;
	string line;
	ifstream inputFile;
	bool tempBool = true;

	inputFile.open(file, ios::in);

	while (inputFile >> word) {
		DataClass* roundInfo = new DataClass;
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
		list.AddItem(roundInfo);
	}
}

double ScoreDifferential(int score, double courseRating, int courseSlope) {
	return ((score - courseRating) * 113) / courseSlope;
}

int main() {
	LinkedList<DataClass> list;
	ReadFile("GolfInfo.txt", list);

	bool quit = false;

	while (!quit) {
		int option;

		Menu();
		cout << "Option choice: ";
		cin >> option;

		if (option == 1) {	// Display handicap
			double handicap = 0;
			int index = 0;
			while (index < list.GetSize()) {
				DataClass* tempRound = new DataClass;
				tempRound = list.SeeItem(index);
				handicap += ScoreDifferential(tempRound->GetPlayerScore(), tempRound->GetCourseRating(), tempRound->GetCourseSlope());
				index++;
			}
			cout << "\nHandicap: " << handicap / index << "\n";
			cout << endl;
		}
		else if (option == 2) {	// Displays full list of data
			list.DisplayList();
		}
		else if (option == 3) {	// Displays full list of course names
			cout << endl;
			for (int i = 0; i < list.GetSize(); i++) {
				cout << list.SeeItem(i)->GetCourseName() << "\n";
			}
			cout << endl;
		}
		else if (option == 4) {	// Displays lowest round
			cout << endl;
			cout << "Lowest round: " << list.SeeItem(0)->GetCourseName() << " - " << list.SeeItem(0)->GetPlayerScore() << "\n";
			cout << endl;

		}
		else if (option == 5) {	// Displays highest round
			cout << endl;
			cout << "Highest round: " << list.SeeItem(list.GetSize() - 1)->GetCourseName() << " - " << list.SeeItem(list.GetSize() - 1)->GetPlayerScore() << "\n";
			cout << endl;
		}
		else if (option == 6) { // Displays easiest course
			cout << endl;
			int easiestCourse = list.SeeItem(0)->GetCourseSlope();
			string easiestName = list.SeeItem(0)->GetCourseName();
			for (int i = 1; i < list.GetSize(); i++) {
				if (list.SeeItem(i)->GetCourseSlope() < easiestCourse) {
					easiestCourse = list.SeeItem(i)->GetCourseSlope();
					easiestName = list.SeeItem(i)->GetCourseName();
				}
			}
			cout << easiestName << " - " << easiestCourse << "\n";
			cout << endl;
		}
		else if (option == 7) { // Displays hardest course
			cout << endl;
			int hardestCourse = list.SeeItem(0)->GetCourseSlope();
			string hardestName = list.SeeItem(0)->GetCourseName();
			for (int i = 1; i < list.GetSize(); i++) {
				if (list.SeeItem(i)->GetCourseSlope() > hardestCourse) {
					hardestCourse = list.SeeItem(i)->GetCourseSlope();
					hardestName = list.SeeItem(i)->GetCourseName();
				}
			}
			cout << hardestName << " - " << hardestCourse << "\n";
			cout << endl;
		}
		else {	// quits program
			quit = true;
		}
	}

	return 0;
}