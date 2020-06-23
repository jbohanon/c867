#pragma once
#include "student.h"


class SoftwareStudent : public Student
{
private:
	Degree m_DegreeType = SOFTWARE;

public:
	Degree getDegreeProgram() override;
	void Print() override;

	SoftwareStudent(std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3); /* : Student::Student(studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse1,
			daysInCourse2,
			daysInCourse3) {}*/
};