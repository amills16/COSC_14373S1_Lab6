#include "Student.h"

student::student()
{ }

student::student(const student & OldStudent)
{
	int c, x;
	size = OldStudent.size;
	for (c = 0; c < size; c++)
	{
		s1[c].name = OldStudent.s1[c].name;
		for (x = 0; x < 5; x++)
			s1[c].grade[x] = OldStudent.s1[c].grade[x];
	}
}

student::~student()
{ }

student student::Copy(const student & OldStudent)
{
	int c, x;
	size = OldStudent.size;
	for (c = 0; c < size; c++)
	{
		s1[c].name = OldStudent.s1[c].name;
		for (x = 0; x < 5; x++)
			s1[c].grade[x] = OldStudent.s1[c].grade[x];
	}
	return *this;
	
}

/*bool student::readFile(const string & fileName)			//JK I fixed it...
{
	string line;
	int c, i = 0;
	ifstream file(fileName);
	if (file.bad())
		return false;
	else
	{
		do {
			getline(file, s1[i].name);
			cout << "Student name: " << s1[i].name << "\t";
			cout << "Grade string: ";
			for (c = 0; c < 4; c++)
			{
				getline(file, line, ',');
				cout << line << ",";
				stringstream converter(line);
				converter >> s1[i].grade[c];
			}
			getline(file, line);
			cout << line << "," << endl;
			stringstream converter(line);
			converter >> s1[i].grade[4];
			i++;
		} while (!file.eof());
		size = i;
	}
	return true;
*/

bool student::readFile(const char * fileName)			//This needs fixing, doesn't read in grades correctly
{
	//string line, name;
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
		while (!file.eof())
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
		}
		size = i;
	}
	return true;
}

bool student::addGrade(const int n, const int c, const int grade)
{
	if (isdigit(grade))
	{
		s1[n].grade[c] = grade;
		return true;
	}
	else
		return false;
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
	return s1[n].grade[c];
}

int student::getAverage(const int & n)
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
	for (i = 0; i < size; i++)
	{
		cout << "Student name: " << s1[i].name << "\t with grades: "; printGrades(i); cout << "\t average grade: " << getAverage(i);
		if (getAverage(i) < 60)
			cout << " FAILURE!" << endl;
		else
			cout << endl;
	}
}

void student::printName(const int & pos)
{
	cout << s1[pos].name;
}

void student::printGrades(const int & pos)
{
	int c = 0;
	for (c; c < 5; c++)
	{
		cout << s1[pos].grade[c] << " ";
	}
}

void student::sortNames(const int & mode)
{
	int i, j;
	students temp;
	if (mode == 1)
	{
		for (i = 0; i < (size - 1); i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (s1[i].name > s1[j].name)
				{
					temp = s1[i];
					s1[i] = s1[j];
					s1[j] = temp;
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
				if (s1[i].name < s1[j].name)
				{
					temp = s1[i];
					s1[i] = s1[j];
					s1[j] = temp;
				}
			}
		}
	}
}
//End;