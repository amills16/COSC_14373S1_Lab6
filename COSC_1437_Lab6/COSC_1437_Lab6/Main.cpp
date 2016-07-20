#include "Student.h"
#include <iostream>

using namespace std;

void main()
{
	string str;
	//cout << "Enter the path of the file you would like to open: ";

	student s1;
	s1.readFile("s1.txt");
	cout << "\n\n\n\n\n";


	s1.printAll();
	cout << "\n\n\n\n\n";


	cout << "Student name: ";
	s1.printName(2);
	cout << "\t with grades: \t";
	s1.printGrades(2);
	cout << "\n\n\n\n\n";

	cout << "Sorting in descending order... \n";
	s1.sortNames(1);
	s1.printAll();
	cout << "\n\n\n\n\n";

	cout << "Sorting in ascending order... \n";
	s1.sortNames(2);
	s1.printAll();

	student s2;
	cout << "\n\n\n\n\n";
	s2.Copy(s1);
	cout << "Printing Student S2 information..." << endl;
	s2.printAll();


	system("PAUSE");
}