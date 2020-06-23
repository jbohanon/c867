#include <iostream>
#include "student.h"

void Student::setStudentID(std::string studentID)
{
	m_StudentID = studentID;
	return;
}
std::string Student::getStudentID() const
{
	return m_StudentID;
}

void Student::setFirstName(std::string firstName)
{
	m_FirstName = firstName;
	return;
}
std::string Student::getFirstName() const
{
	return m_FirstName;
}

void Student::setLastName(std::string lastName)
{
	m_LastName = lastName;
	return;
}
std::string Student::getLastName() const
{
	return m_LastName;
}

void Student::setEmailAddress(std::string emailAddress)
{
	m_EmailAddress = emailAddress;
	return;
}
std::string Student::getEmailAddress() const
{
	return m_EmailAddress;
}
	
void Student::setAge(int age)
{
	m_Age = age;
	return;
}
int Student::getAge() const
{
	return m_Age;
}

void Student::setDaysToCompleteCourse1(int daysToCompleteCourse1)
{
	m_DaysInCourses[0] = daysToCompleteCourse1;
	return;
}
int Student::getDaysToCompleteCourse1() const
{
	return m_DaysInCourses[0];
}

void Student::setDaysToCompleteCourse2(int daysToCompleteCourse2)
{
	m_DaysInCourses[1] = daysToCompleteCourse2;
	return;
}
int Student::getDaysToCompleteCourse2() const
{
	return m_DaysInCourses[1];
}

void Student::setDaysToCompleteCourse3(int daysToCompleteCourse3)
{
	m_DaysInCourses[2] = daysToCompleteCourse3;
	return;
}
int Student::getDaysToCompleteCourse3() const
{
	return m_DaysInCourses[2];
}

void Student::Print() {
}

Degree Student::getDegreeProgram() { return SECURITY; };

Student::Student(std::string studentID,
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
}

Student::Student() 
{
	m_StudentID = "";
	m_FirstName = "";
	m_LastName = "";
	m_EmailAddress = "";
	m_Age = -1;
	m_DaysInCourses[0] = -1;
	m_DaysInCourses[1] = -1;
	m_DaysInCourses[2] = -1;
}

Student::~Student() {

}
