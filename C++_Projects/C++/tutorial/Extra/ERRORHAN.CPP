#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");

	// Initialize a number so it was always set to zero
	//int number=0;
	int number = 0;

	cout<<"Enter a number: ";
	cin>>number;

	while(cin.fail())
	{
	    system("cls");
		cin.clear();
		cin.ignore();
		cout<<"Please enter a valid number: ";
		cin>>number;
	}

	cout<<"The number you entered: "<< number;

	cout<<endl<<endl;
	cin.get();
}
