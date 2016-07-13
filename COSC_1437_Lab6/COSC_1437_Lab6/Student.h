#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <istream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <WCS_String.h>


class student
{
public:
	student();
	student(const string, const int [5]);
	student(const char [], const int[5]);
	student(const student &);
	student Copy(const string &);
	student Copy(const student &);
	bool readFile(const char *);
	bool readFile(const string &);
	bool addGrade(int, int);
	int getGrade(int) const;
	int getAverage() const;
	const string getName();
	~student();
private:
	string studentName;
	int grades [5];
	int average;
};
#endif // !STUDENT_H
