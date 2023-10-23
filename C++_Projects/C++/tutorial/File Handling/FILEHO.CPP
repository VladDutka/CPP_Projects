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
	ofstream output;

	cout<<"Enter your desired filename: ";
	cin.getline(filename,20,'\n');

	output.open(filename,ios::out);

	cout<<endl<<"Enter a word or a phrase that you want to save in the file: "<<endl;
	cout<<"Enter: ";
	cin.getline(text,50,'\n');

	output<<text;
	output.close();

	cout<<endl;
	cout<<"Your file was saved to: "<<filename<<endl;
	cout<<"Please press any key to terminate the program";



	cin.get();
}
