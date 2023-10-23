#include <iostream>
#include <windows.h>

using namespace std;

//gotoxy for boxes
COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
	system("cls");

	gotoxy(34,2);cout<<"The Alphabet"<<endl<<endl;
	for(int ctr=0;ctr<26;ctr++)
	{
		cout<<char(65+ctr)<<char(97+ctr)<<" ";
	}

	cin.get();
}
