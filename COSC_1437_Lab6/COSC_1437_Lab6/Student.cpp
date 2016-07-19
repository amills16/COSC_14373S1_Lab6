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
	return average[n];
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

/*bool student::readFile(const char * fileName)			//This needs fixing, doesn't read in names correctly
{
	string line, name;
	int c; 
	int i = 0;
	ifstream file(fileName);
	if (file.bad())
		return false;
	else
	{
		do {
			getline(file, s1[i].name);
			cout << "Student name: " << s1[i].name << "\t";
			cout << "Grade string: ";
			for (c = 0; c < 5; c++)
			{
				getline(file, line, ',');
				cout << line << ",";
				stringstream converter(line);
				converter >> s1[i].grade[c];
			}
			cout << endl;
			i++;
		} while (!file.eof());
	}
	return true;
}*/

bool student::readFile(const char * fileName)			//This needs fixing, doesn't read in grades correctly
{
	string line, name;
	char lines [256] = "";
	char * pChar = "";
	char separators[] = ",";
	int c = 0, i = 0;
	ifstream file;
	file.open(fileName,ios_base::in);
	if (file.bad())
		return false;
	else
	{
		while (!file.eof())
		{
			file.getline(lines, 256, '\n');
			s1[i].name = lines;
			cout << "Student name: " << s1[i].name << "\t";
			cout << "Grade string: ";
			file.getline(lines, 256);
			pChar = strtok(lines, separators);
			do {
				s1[i].grade[c] = atoi(pChar);
				cout << s1[i].grade[c] << ",";
				c++;
				pChar = strtok(NULL, separators);
			} while (pChar != NULL);
			cout  << endl;
			i++;
		} 
	}
	return true;
}

//End;