#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <istream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "newArray.h"
#include <wcs_string.h>

class student : public WCS_String
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
	struct students {
		std::string name;
		int grade[5];
		int average;
	};students s1[25]; // make array of students a class object
	int size;
};
#endif // !STUDENT_H
