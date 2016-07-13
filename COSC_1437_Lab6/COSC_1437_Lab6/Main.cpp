#include "Student.h"
#include <iostream>

using namespace std;

void main()
{
	string str1 = "John";
	int g1[5] = { 100, 95, 72, 87, 91 };
	student s1;
	student s2(str1, g1);
	student s3;
	s1.readFile("s1.txt");
	s3.readFile("s2.txt");
	cout << "Student Name: " << s3.getName() << "Average: " << s3.getAverage() << endl;
	cout << s1.getAverage() << endl;
	system("PAUSE");
}