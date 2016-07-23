#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <wcs_string.h>

using namespace std;


class student : public WCS_String
{
public:
				student			();
				student			(const student &);
	student		copy			(const student &);
	bool		readFile		(fstream &);
	bool		addGrade		(const int, const int, const int);
	bool		compareStudent	(const student &, const int &);
	bool		compareStudent	(const student &, const string &);
	bool		compareStudent	(const string &, const string &);
	int			getGrade		(const int &, const int &);
	int			getAverage		();
	string		printName		();
	void		printGrades		();
				~student		();
	student &	operator =		(const student &);
private:
	string		name;
	int			grade[5];
	double		average;
};

class studArray
{
public:
				studArray();
	bool		read(const string &);
	void		printAll();
	void		sortNames(const int &);
	studArray	copy(const studArray &);
	studArray &	operator =		(const studArray &);
				~studArray();
private:
	vector		<student> Students;
	int			size;

};
#endif // !STUDENT_H

inline student & student::operator = (const student & newStud)
{
	return copy(newStud);
}

inline studArray & studArray::operator = (const studArray & newStud)
{
	return copy(newStud);
}
