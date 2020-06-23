#pragma once
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include <fstream>
#include <vector>

class Roster {

private:
	int addIndex = 0;

public:
	Student* classRosterArray[5]; // 5-element array to hold parsed student info and up to one new student

	// function declarations
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	// constructor and destructor declarations
	Roster();
	~Roster();
};