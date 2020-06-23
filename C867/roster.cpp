#include "roster.h"
#include <string>
#include <cstring>
#include <vector>


Roster::Roster() 
{
	return;
}

Roster::~Roster() 
{
	return;
}


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) 
{

	if (degreeProgram == NETWORKING) 
	{
		classRosterArray[addIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	else if (degreeProgram == SECURITY)
	{
		classRosterArray[addIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	else if (degreeProgram == SOFTWARE)
	{
		classRosterArray[addIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
	}

	addIndex++;

	return;
}

void Roster::remove(std::string studentID)
{
	bool studentFound = false;

	for (int n = 0; n < 5; ++n) 
	{
		if (Roster::classRosterArray[n]->getStudentID() == studentID)
		{
			classRosterArray[n]->~Student();
			studentFound = true;
			break;
		}
	}
	if(!studentFound)
	{
		std::cout << "Student with ID " << studentID << " could not be round in the roster.";
	}

	return;
}

void Roster::printAll()
{

	for (int n = 0; n < 5; ++n)
	{
		classRosterArray[n]->Print();
	}

	return;
}

void Roster::printAverageDaysInCourse(std::string studentID) 
{
	//Student* tempStudent;

	const int numInRoster = sizeof(Roster::classRosterArray) / sizeof(*Roster::classRosterArray);

	for (int n = 0; n < numInRoster; ++n)
	{
		if (Roster::classRosterArray[n]->getStudentID() == studentID) 
		{
			double avg = (static_cast<double>(Roster::classRosterArray[n]->getDaysToCompleteCourse1()) + static_cast<double>(Roster::classRosterArray[n]->getDaysToCompleteCourse2()) + static_cast<double>(Roster::classRosterArray[n]->getDaysToCompleteCourse3())) / 3.0;
			std::cout << "Average days across 3 classes for " << Roster::classRosterArray[n]->getFirstName() << " " << Roster::classRosterArray[n]->getLastName() << ": " << avg << std::endl;
		}
	}

	return;
}

void Roster::printInvalidEmails()
{

	std::cout << "Invalid emails:" << std::endl;

	for (int n = 0; n < 5; ++n)
	{
		std::string tempstr = classRosterArray[n]->getEmailAddress();
		if ((tempstr.find(' ') != std::string::npos) || (tempstr.find('@') == std::string::npos) || (tempstr.find('.') == std::string::npos))
		{
			std::cout << tempstr << std::endl;
		}
	}
	return;
}

void Roster::printByDegreeProgram(int degreeProgram)
{

	for (int n = 0; n < 5; ++n)
	{
		int localDegProgram = Roster::classRosterArray[n]->getDegreeProgram();
		if(localDegProgram == degreeProgram)
		{
			Roster::classRosterArray[n]->Print();
		}
	}

	return;
}


int main() {

	const std::string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jacob,Bohanon,jbohano@wgu.edu,25,18,60,32,SOFTWARE" };

	std::cout << "Course: C867 Scripting and Programming Applications" << std::endl;
	std::cout << "C++" << std::endl;
	std::cout << "Student ID: 001091919" << std::endl;
	std::cout << "Jacob Bohanon" << std::endl;

	Roster* classRoster = new Roster();

	for (int i = 0; i < 5; ++i) // loop for each student to put discrete data points into array for access by class constructor
	{
		const char delim = ',';
		const char* tempChars = studentData[i].c_str();
		int numOfChars = studentData[i].length();
		std::string tempArr[9];// = new std::string[9]; // temporary array to hold discrete data points for a single student

		int index = 0;
		for (int n = 0; n < 9; ++n) // 9 fields per student 
		{
			try
			{
				std::string tempStr = ""; // temporary string to hold individual discrete data point while looking for ',' delimiter
				while ((*(tempChars + index) != delim) && index < numOfChars + 1) // cycle through individual chars and add them to a running string until a comma is found
				{
					tempStr += *(tempChars + index);
					++index;
				}
				tempArr[n] = tempStr;
				++index;
			}
			catch(std::runtime_error)
			{
				break;
			}
		}

		const char* tempDegStr = tempArr[8].c_str();
		Degree tempDeg = SECURITY;
		
		if (strcmp(tempDegStr, "NETWORK") == 0)
		{
			tempDeg = NETWORKING;
		}
		else if (strcmp(tempDegStr, "SOFTWARE") == 0)
		{
			tempDeg = SOFTWARE;
		}

		classRoster->add(tempArr[0], tempArr[1], tempArr[2], tempArr[3], std::stoi(tempArr[4]), std::stoi(tempArr[5]), std::stoi(tempArr[6]), std::stoi(tempArr[7]), tempDeg);

	}


	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (int n = 0; n < 5; ++n) 
	{
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[n]->getStudentID());
	}

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");

	classRoster->~Roster();
	return 0;
}