#include <iostream>
#include <string>
#include "roster.h"


using namespace std;

int main() {
	//Student data with A5 being my own information 
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jason,Padilla,jpad178@wgu.edu,26,30,40,33,SOFTWARE"
	};


	//Print out my information
	cout << "C867 Scripting and Programming - Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "student ID: 012259608" << endl;
	cout << "Name: Jason Padilla" << endl << endl;


	Roster classRoster;

	//Displaying Students
	cout << "Displaying all students: " << endl;
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();
	cout << endl;

	//Display invalid emails
	cout << "Displaying invalid emaials:" << endl << endl;
	classRoster.printInvalidEmails();

	cout << endl;

	//Displaying average days in course via student ID
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }

	cout << endl;
	
	//Displaying students via degree program
	cout << "Showing students in degree program: " << "SOFTWARE" << endl << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	//Removing student A3
	cout << endl << "Removing: A3" << endl << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl << endl;

	//Removing student A3 again
	classRoster.remove("A3");

	cout << "DONE.";

	//Destructor to release memory
	classRoster.~Roster();

	return 0;
}