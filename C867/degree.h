#pragma once

enum Degree
{
	SECURITY,
	NETWORKING,
	SOFTWARE
};

static const char* printDegreeType(int degree) 
{
	switch (degree)
	{
		case 0: return "SECURITY";
		case 1: return "NETWORKING";
		case 2: return "SOFTWARE";

		default: return 0;
	}
}