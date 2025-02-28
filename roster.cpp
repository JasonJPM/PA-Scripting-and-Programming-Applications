#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//Constructor
Roster::Roster() {
	for (int i = lastIndex; i < 5; i++)
		classRosterArray[i] = nullptr;
}

//Destructor
Roster::~Roster() {
	for (int i = lastIndex; i < 5; i++)
		if (classRosterArray[i] != nullptr)
			delete classRosterArray[i];
}

//Parsing student data
void Roster::parse(string row) {

	//Student ID
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	//First Name
	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	//Last Name
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	//Email address
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	//Age
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int Age = stoi(row.substr(lhs, rhs - lhs));

	//Days In Course 1, 2, 3
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	//Degree Program
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string strdegreeProgram = row.substr(lhs, rhs - lhs);
	
	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
	if (strdegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY; }

	else if (strdegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (strdegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	//Adding the students to the roster array
	add(studentID, firstName, lastName, emailAddress, Age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//Adding new Student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[lastIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

//Removing Student
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			found = true;
			break;
		}
	}
	if (!found) cout << "The Student with the ID: " << studentID << " was not found." << endl;
}

//Print All
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr)
			classRosterArray[i]->print();
	}
}

//Print Invalid Emails
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr)
			continue;
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
			cout << email << " - is invalid." << endl;
		}
	}
}

//Printing avg days in course using student ID
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			int* getDaysInCourse = classRosterArray[i]->getDaysInCourse();
			cout << "Student ID: " << studentID << ", average days in course is: " <<
				(getDaysInCourse[0] + getDaysInCourse[1] + getDaysInCourse[2]) / 3 << endl;
		}
	}
}

//Print by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}