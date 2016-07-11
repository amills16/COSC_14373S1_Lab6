#include "Student.h"

student::student()
{ }

student::student(const string name, const int newGrades[5] )
{
	studentName = name;
	for (int i = 0; i < 5; i++)
		grades[i] = newGrades[i];
	average = getAverage();
}

student::student(const char name[], const int newGrades[5])
{
	studentName = name;
	for (int i = 0; i < 5; i++)
		grades[i] = newGrades[i];
	average = getAverage();
}

student::student(const student &)
{ }

student::~student()
{ }

bool student::addGrade(int c, int grade)
{
	if (isdigit(grade))
	{
		grades[c] = grade;
		return true;
	}
	else
		return false;
}

int student::getAverage()
{
	int i, total;
	for (i = 0, total = 0; i < 5; i++)
	{
		total += grades[i];
	}
	int tempAverage = total/5;
	return tempAverage;
}

int student::getGrade(int c)
{
	return grades[c];
}

bool student::readFile(const char * fileName)
{
	string line, name;
	int c;
	ifstream file(fileName);
	if (file.bad())
		return false;
	else
	{
		getline(file, studentName, '\n');
		cout << "Student name: " << studentName << endl;
		getline(file, line);
		cout << "Grade string: " << line << endl;
		for (c = 0; c < 5; c++)
		{
			stringstream converter(line);
			converter >> grades[c];
		}
	}
	return true;
}