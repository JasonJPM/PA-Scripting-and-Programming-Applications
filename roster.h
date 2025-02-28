#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <string>

using namespace std;

class Roster {
	public:
		Student* classRosterArray[5];							//Array of pointers to Student objects
		int lastIndex = 0;										

		Roster();												//Constructor
		~Roster();												//Destructor to free memory

		void parse(string row);									//Parsing
		void add(string studentID, string firstName, string lastName, string emailAddress, int age,
			int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);	//Add
		void remove(string studentID);							//Remove
		void printAll();										//Print all
		void printInvalidEmails();								//Print invalid emails
		void printAverageDaysInCourse(string studentID);		//Print average days in course
		void printByDegreeProgram(DegreeProgram degreeProgram);	//Print by degree program

};

#endif