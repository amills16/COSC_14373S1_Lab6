#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <istream>
#include <fstream>
#include <sstream>
#include <wcs_string.h>
//Add in sort function
//Must make sure multiple students' data can be taken in through the same file

class student : public WCS_String
{
public:
	student();
	student(const student &);
	student Copy(const string &);
	student Copy(const student &);
	bool readFile(const char *);
	bool addGrade(int, int, int);
	int getGrade(int, int);
	int getAverage(int);
	void printAll();
	void printGrades(int);
	~student();
	struct students {
		string name;
		int grade[5];
	}; students s1 [25];
private:
	string studentName;
	int grades [5];
	int average[50];
};
#endif // !STUDENT_H
