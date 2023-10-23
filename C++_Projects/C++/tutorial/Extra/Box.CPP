#include <iostream>
#include <windows.h>
#include <dos.h>

using namespace std;

//gotoxy for boxes
COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void box()
{
    //horizontal
    for(int ctr=0; ctr<=80; ctr++)
    {
        gotoxy(ctr,1); cout<<char(178);
        gotoxy(ctr,25); cout<<char(178);
        Sleep(20);
    }
    //vertical
    for(int ctr2=1; ctr2<25; ctr2++)
    {
        gotoxy(0,ctr2); cout<<char(178);
        gotoxy(80,ctr2); cout<<char(178);
        Sleep(20);
    }
}

int main()
{
	system("cls");

	box();

	gotoxy(34,5);cout<<"The Alphabet"<<endl<<endl;
	gotoxy(2,8);
	for(int ctr=0;ctr<26;ctr++)
	{
		cout<<char(65+ctr)<<char(97+ctr)<<" ";
		Sleep(100);
	}

	cin.get();
}
