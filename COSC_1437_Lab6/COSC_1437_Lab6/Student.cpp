#include "Student.h"



student::student()
{ }

student::student(const student & OldStudent)
{
	int c, x;
		name = OldStudent.name;
		for (x = 0; x < 5; x++)
			grade[x] = OldStudent.grade[x];
}

student::~student()
{ }

student student::copy(const student & OldStudent)
{
	int c, x;
		name = OldStudent.name;
		for (x = 0; x < 5; x++)
			grade[x] = OldStudent.grade[x];
	return *this;
	
}

bool student::readFile(fstream & file)			//JK I fixed it...
{
	string line;
	int c, i = 0;
	{
		getline(file, name);
		cout << "Student name: " << name << "\t";
		cout << "Grade string: ";
		for (c = 0; c < 4; c++)
		{
			getline(file, line, ',');
			cout << line << ",";
			stringstream converter(line);
			converter >> grade[c];
		}
		getline(file, line);
		cout << line << "," << endl;
		stringstream converter(line);
		converter >> grade[4];
		i++;
	}
	return true;
}

/*bool student::readFile(const char * fileName)			//This needs fixing, doesn't read in grades correctly
{
	char lines[256] = "";
	char * pChar = "";
	char separators[] = ",";
	int c, i = 0;
	ifstream file;
	file.open(fileName, ios_base::in);
	if (file.bad())
		return false;
	else
	{
		do
		{
			c = 0;
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
			cout << endl;
			i++;
		} while (!file.eof());
		size = i;
	}
	return true;
}*/

bool student::addGrade(const int n, const int c, const int grades)
{
		grade[c] = grades;
		return true;
}

bool student::compareStudent(const student & compareList, const int & studentNumber)
{
	return false;
}

bool student::compareStudent(const student & compareList, const string & studentName)
{
	return false;
}

bool student::compareStudent(const string & studentNameA, const string & studentNameB)
{
	return false;
}

int student::getGrade(const int & n, const int & c)
{
	return grade[c];
}

int student::getAverage()
{
	double total;
	int i;
	for (i = 0, total = 0; i < 5; i++)
		total += grade[i];
	average = total * .2;
	return average;
}

string student::printName()
{
	return name;
}

void student::printGrades()
{
	int c = 0;
	for (c; c < 5; c++)
	{
		cout << grade[c] << " ";
	}
}




//----------------------------------Student Array Code----------------------------------//


studArray::studArray()
{
	Students.resize(25);
}
studArray studArray::copy(const studArray & oldStudArray)
{
	int i;
	for (i = 0; i < size; i++)
	{
		Students[i] = oldStudArray.Students[i];
	}
	return *this;
}
bool studArray::read(const string & fileName)
{
	int i=0;
	fstream file(fileName);
	if (file.bad())
		return false;
	else
	{
		do
		{
			Students[i].student::readFile(file);
			i++;
		} while (!file.eof());
		size = i;
		return true;
	}
}
void studArray::printAll()
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << "Student name: " << Students[i].printName() << "\t with grades: "; Students[i].printGrades(); cout << "\t average grade: " << Students[i].getAverage();
		if (Students[i].getAverage() < 60)
			cout << " FAILURE!" << endl;
		else
			cout << endl;
	}
}
void studArray::sortNames(const int & mode)
{
	int i, j;
	student temp;
	if (mode == 1)
	{
		for (i = 0; i < (size - 1); i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (Students[i].printName() > Students[j].printName())
				{
					temp = Students[i];
					Students[i] = Students[j];
					Students[j] = temp;
				}
			}
		}
	}
	else
	{
		for (i = 0; i < (size - 1); i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (Students[i].printName() < Students[j].printName())
				{
					temp = Students[i];
					Students[i] = Students[j];
					Students[j] = temp;
				}
			}
		}
	}
}
studArray::~studArray()
{
}
//End;