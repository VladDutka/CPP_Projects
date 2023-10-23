#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
	system("cls");
	//filename
	char filename[20];
	char text[50];

	//variable declaration for creating file
	ifstream input;

	cout<<"Enter your filename to open: ";
	cin.getline(filename,20,'\n');

	input.open(filename,ios::in);

	cout<<endl;
	if(!input)
    {
        cout<<"Awts wala siya parekoy, baka napunta na sa iba T_T"<<endl;
    }
    else
    {
        input.getline(text,50,'\n');
        input>>text;
        cout<<"The text inside the file is: "<<text<<endl;
    }
    input.close();

	cin.get();
}
