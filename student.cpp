#include <iostream>
#include <string>
#include "student.h"

using namespace std;


//Constructors
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}



//Getter functions (accessors)
string Student::getStudentID() {
	return studentID; }

string Student::getFirstName() {
	return firstName; }

string Student::getLastName() {
	return lastName; }

string Student::getEmailAddress() {
	return emailAddress; }

int Student::getAge() {
	return age; }

int* Student::getDaysInCourse() {
	return daysInCourse; }

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram; }



//Setter functions (mutators)
void Student::setStudentID(string studentID) {
	this->studentID = studentID; }

void Student::setFirstName(string firstName) {
	this->firstName = firstName; }

void Student::setLastName(string lastName) {
	this->lastName = lastName; }

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress; }

void Student::setAge(int age) {
	this->age = age; }

void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram; }

//Print function
void Student::print() {
	string degreeProgram_string;
	   if (degreeProgram == DegreeProgram::SECURITY) {
		   degreeProgram_string = "SECUIRTY"; }
	   else if (degreeProgram == DegreeProgram::NETWORK) {
		   degreeProgram_string = "NETWORK"; }
	   else if (degreeProgram == DegreeProgram::SOFTWARE) {
		   degreeProgram_string = "SOFTWARE"; }
	
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t" << "\t";
	cout << getAge() << "\t";
	cout << "{" << getDaysInCourse()[0] << "," << getDaysInCourse()[1] << "," << getDaysInCourse()[2] << "}\t";
	cout << degreeProgram_string << endl;
};