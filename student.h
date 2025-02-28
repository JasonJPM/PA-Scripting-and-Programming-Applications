#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	//Constructors
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse[], DegreeProgram degreeProgram);

	//Getter functions (accessors)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int *getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Setter functions (mutators)
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print function
	void print();
};

#endif