#include "Student.h"
#include <iostream>

using namespace std;

void main()
{
	string str1 = "John";
	int g1[5] = { 100, 95, 72, 87, 91 };
	student s1;
	s1.readFile("s1.txt");
	s1.printAll();
	system("PAUSE");
}