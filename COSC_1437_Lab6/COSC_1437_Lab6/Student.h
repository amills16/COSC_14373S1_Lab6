#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <istream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "newArray.h"
#include <wcs_string.h>

class student : private newArray
{
public:
	student();
	student(const student &);
	student Copy(const student &);
	bool readFile(const char *);
	bool addGrade(const int, const int, const int);
	bool compareStudent(const student &, const int &);
	bool compareStudent(const student &, const string &);
	bool compareStudent(const string &, const string &);
	int getGrade(const int &, const int &);
	int getAverage(const int &);
	void printAll();
	void printName(const int &);
	void printGrades(const int &);
	void sortNames(const int &);
	~student();
private:
	students s1[25];
	int size;
	int average[25];
};
#endif // !STUDENT_H
