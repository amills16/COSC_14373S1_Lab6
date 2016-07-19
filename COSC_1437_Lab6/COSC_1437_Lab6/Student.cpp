#include "Student.h"

student::student()
{
}

student::student(const student &)
{ }

student::~student()
{ }

bool student::addGrade(int n, int c, int grade)
{
	if (isdigit(grade))
	{
		s1[n].grade[c] = grade;
		return true;
	}
	else
		return false;
}

int student::getAverage(int n)
{
	int i, total;
	for (i = 0, total = 0; i < 5; i++)
		total += s1[n].grade[i];
	int tempAverage = total/5;
	average[n] = tempAverage;
	return tempAverage;
}

void student::printAll()
{
	int i;
	for (i = 0; i < 25; i++)
	{
		cout << "Student name: " << s1[i].name << "\t with grades: "; printGrades(i); cout << "\t average grade: " << getAverage(i) << endl;
	}
}

void student::printGrades(int i)
{
	int c = 0;
	for (c; c < 5; c++)
	{
		cout << s1[i].grade[c] << " ";
	}
}

int student::getGrade(int n, int c)
{
	return s1[n].grade[c];
}

bool student::readFile(const char * fileName)
{
	string line, name;
	int c; 
	int i = 0;
	char *	pChar;
	char	Seps[] = ", .;";
	ifstream file(fileName);
	if (file.bad())
		return false;
	else
	{
		do {
			if(i==0)
				getline(file, s1[i].name, '\n');
			cout << "Student name: " << s1[i].name << "\t";
			cout << "Grade string: ";
			for (c = 0; c < 5; c++)
			{
				getline(file, line, ',');
				cout << line << " ";
				stringstream converter(line);
				if (c == 0 && i !=0)
					converter >> s1[i].name;
				converter >> s1[i].grade[c];
			}
			cout << endl;
			i++;
			//getline(file, s1[i].name, '\n');
		} while (!file.eof());
	}
	return true;
}

//End;