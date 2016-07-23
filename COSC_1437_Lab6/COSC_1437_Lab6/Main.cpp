#include "Student.h"
#include <iostream>

using namespace std;

void main()
{
	string str;
	cout << "Enter the path of the file you would like to open: ";
	cin >> str;
	studArray s1;
	s1.read(str);
	cout << "\n\n\n\n\n";


	s1.printAll();
	cout << "\n\n\n\n\n";

	cout << "Sorting in descending order... \n";
	s1.sortNames(1);
	s1.printAll();
	cout << "\n\n\n\n\n";

	cout << "Sorting in ascending order... \n";
	s1.sortNames(2);
	s1.printAll();


	system("PAUSE");
}