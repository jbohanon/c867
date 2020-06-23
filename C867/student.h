#pragma once
#include <iostream>
#include <string>
#include "degree.h"

class Student {

protected:
	std::string m_StudentID;
	std::string m_FirstName;
	std::string m_LastName;
	std::string m_EmailAddress;
	int m_Age;
	int m_DaysInCourses[3];
	int m_DegreeType;


public:

	void setStudentID(std::string studentID);
	std::string getStudentID() const;

	void setFirstName(std::string firstName);
	std::string getFirstName() const;

	void setLastName(std::string lastName);
	std::string getLastName() const;

	void setEmailAddress(std::string emailAddress);
	std::string getEmailAddress() const;

	void setAge(int age);
	int getAge() const;

	void setDaysToCompleteCourse1(int daysToCompleteCourse1);
	int getDaysToCompleteCourse1() const;

	void setDaysToCompleteCourse2(int daysToCompleteCourse2);
	int getDaysToCompleteCourse2() const;

	void setDaysToCompleteCourse3(int daysToCompleteCourse3);
	int getDaysToCompleteCourse3() const;

	virtual void Print();

	virtual Degree getDegreeProgram();

	Student(std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3);

	Student();

	~Student();
};