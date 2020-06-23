#pragma once
#include "student.h"


class SecurityStudent : public Student
{
private:
	Degree m_DegreeType = SECURITY;

public:
	Degree getDegreeProgram() override;
	void Print() override;

	SecurityStudent(std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3); /*: Student::Student(studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse1,
			daysInCourse2,
			daysInCourse3) {}*/
};