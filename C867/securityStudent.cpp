#include "securityStudent.h"

Degree SecurityStudent::getDegreeProgram() {
	return m_DegreeType;
}

SecurityStudent::SecurityStudent(std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3)
{
	m_StudentID = studentID;
	m_FirstName = firstName;
	m_LastName = lastName;
	m_EmailAddress = emailAddress;
	m_Age = age;
	m_DaysInCourses[0] = daysInCourse1;
	m_DaysInCourses[1] = daysInCourse2;
	m_DaysInCourses[2] = daysInCourse3;
	m_DegreeType = SECURITY;
}

void SecurityStudent::Print() {
	std::cout << this->getStudentID().substr(1, 1) + '\t' + "First Name: " + this->getFirstName() + '\t' + "Last Name: " + this->getLastName() + '\t' + "Age: " << std::to_string(this->getAge()) << '\t' << "daysInCourse: {" << std::to_string(this->getDaysToCompleteCourse1()) << ", " << std::to_string(this->getDaysToCompleteCourse2()) << ", " << std::to_string(this->getDaysToCompleteCourse3()) << "} Degree Program: " << printDegreeType(this->getDegreeProgram()) << std::endl;

	return;
}