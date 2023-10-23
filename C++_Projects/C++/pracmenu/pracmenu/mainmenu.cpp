
// reconstruct login

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<math.h>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stack>
#include <vector>
#include <algorithm>
//#include <bits-stdc++.h>
#include<fstream>
#include<stdlib.h>
#include "menufunc.h" //CONTAINS SUB MENUS

using namespace std;
using std::string;
using std::vector;

void main()
{
	system("CLS"); 
	border();
	// VARIABLES OF LOGIN
	char uname[20];
	char password[10];

	for (int rowe = 52; rowe <= 68; rowe++)
	{
		gotoxy(rowe, 6);
		cout << "=";
		gotoxy(rowe, 8);
		cout << "=";
	}
	for (int cole = 6; cole <= 8; cole++)
	{
		gotoxy(52, cole);
		cout << "||";
		gotoxy(68, cole);
		cout << "||";
	}

	//LOGIN 
	gotoxy(58, 7);
	cout << "Log in";
	gotoxy(47, 11);
	cout << "Enter username: ";
	cin >> uname;
	gotoxy(47, 13);
	cout << "Enter password: ";
	cin >> password;
	gotoxy(51, 15);
	if (strcmp(uname, "Geoffrey") == 0 && strcmp(password, "rendon") == 0)
	{
		cout << "Access Granted";
	}
	else
	{
		cout << "Invalid";
		exit(0);
	}
	_getch();

	//PARENT MAINMENU
	char pili;
	do {
		system("CLS");
		border();
		for (int rowe = 54; rowe <= 66; rowe++)
		{
			gotoxy(rowe, 4);
			cout << "=";
			gotoxy(rowe, 6);
			cout << "=";
		}
		for (int cole = 4; cole <= 6; cole++)
		{
			gotoxy(54, cole);
			cout << "||";
			gotoxy(66, cole);
			cout << "||";
		}
		gotoxy(56, 5);
		WriteInColor(80, " MAINMENU ");
		WriteInColor(06, "");

		//choices sa mainmenu
		//choiceA
		for (int rowa = 18; rowa <= 37; rowa++)
		{
			gotoxy(rowa, 9);
			cout << "=";
			gotoxy(rowa, 11);
			cout << "=";
		}
		for (int cola = 9; cola <= 11; cola++)
		{
			gotoxy(18, cola);
			cout << "||";
			gotoxy(37, cola);
			cout << "||";
		}
		gotoxy(20, 10);
		WriteInColor(75, "A. "); WriteInColor(05, "Sequence Menu");
		//choiceB
		for (int rowb = 40; rowb <= 60; rowb++)
		{
			gotoxy(rowb, 9);
			cout << "=";
			gotoxy(rowb, 11);
			cout << "=";
		}
		for (int colb = 9; colb <= 11; colb++)
		{
			gotoxy(40, colb);
			cout << "||";
			gotoxy(60, colb);
			cout << "||";
		}
		gotoxy(42, 10);
		WriteInColor(71, "B. "); WriteInColor(01, "Selection Menu");
		//choiceC
		for (int rowc = 63; rowc <= 83; rowc++)
		{
			gotoxy(rowc, 9);
			cout << "=";
			gotoxy(rowc, 11);
			cout << "=";
		}
		for (int colc = 9; colc <= 11; colc++)
		{
			gotoxy(63, colc);
			cout << "||";
			gotoxy(83, colc);
			cout << "||";
		}
		gotoxy(65, 10);
		WriteInColor(72, "C. "); WriteInColor(02, " Iteration Menu");
		//choiceD
		for (int rowd = 86; rowd <= 106; rowd++)
		{
			gotoxy(rowd, 9);
			cout << "=";
			gotoxy(rowd, 11);
			cout << "=";
		}
		for (int cold = 9; cold <= 11; cold++)
		{
			gotoxy(86, cold);
			cout << "||";
			gotoxy(106, cold);
			cout << "||";
		}
		gotoxy(88, 10);
		WriteInColor(73, "D. "); WriteInColor(03, " 1D-Array Menu");
		//choiceE
		for (int rowe = 18; rowe <= 37; rowe++)
		{
			gotoxy(rowe, 14);
			cout << "=";
			gotoxy(rowe, 16);
			cout << "=";
		}
		for (int cole = 14; cole <= 16; cole++)
		{
			gotoxy(18, cole);
			cout << "||";
			gotoxy(37, cole);
			cout << "||";
		}
		gotoxy(20, 15);
		WriteInColor(79, "E. "); WriteInColor(04, " 2D-Array Menu");
		//choiceF
		for (int rowf = 40; rowf <= 60; rowf++)
		{
			gotoxy(rowf, 14);
			cout << "=";
			gotoxy(rowf, 16);
			cout << "=";
		}
		for (int colf = 14; colf <= 16; colf++)
		{
			gotoxy(40, colf);
			cout << "||";
			gotoxy(60, colf);
			cout << "||";
		}
		gotoxy(42, 15);
		WriteInColor(78, "F. "); WriteInColor(05, " Recursion Menu");
		//choiceG
		for (int rowg = 63; rowg <= 83; rowg++)
		{
			gotoxy(rowg, 14);
			cout << "=";
			gotoxy(rowg, 16);
			cout << "=";
		}
		for (int colg = 14; colg <= 16; colg++)
		{
			gotoxy(63, colg);
			cout << "||";
			gotoxy(83, colg);
			cout << "||";
		}
		gotoxy(65, 15);
		WriteInColor(79, "G. "); WriteInColor(06, " Pointers Menu");
		//choiceH
		for (int rowh = 86; rowh <= 106; rowh++)
		{
			gotoxy(rowh, 14);
			cout << "=";
			gotoxy(rowh, 16);
			cout << "=";
		}
		for (int colh = 14; colh <= 16; colh++)
		{
			gotoxy(86, colh);
			cout << "||";
			gotoxy(106, colh);
			cout << "||";
		}
		gotoxy(88, 15);
		WriteInColor(79, "H. "); WriteInColor(01, " Structures");
		//choiceI
		for (int rowi = 31; rowi <= 50; rowi++)
		{
			gotoxy(rowi, 19);
			cout << "=";
			gotoxy(rowi, 21);
			cout << "=";
		}
		for (int coli = 19; coli <= 21; coli++)
		{
			gotoxy(31, coli);
			cout << "||";
			gotoxy(50, coli);
			cout << "||";
		}
		gotoxy(33, 20);
		WriteInColor(79, "I. "); WriteInColor(02, " File Handling");
		//choiceJ
		for (int rowj = 74; rowj <= 93; rowj++)
		{
			gotoxy(rowj, 19);
			cout << "=";
			gotoxy(rowj, 21);
			cout << "=";
		}
		for (int colj = 19; colj <= 21; colj++)
		{
			gotoxy(74, colj);
			cout << "||";
			gotoxy(93, colj);
			cout << "||";
		}
		gotoxy(78, 20);
		WriteInColor(79, "J. "); WriteInColor(03, " Exit");

		gotoxy(52, 23);
		WriteInColor(011, "Enter the chosen menu: ");
		gotoxy(75, 23);
		cin >> pili;

		switch (pili)
		{
		case 'A':
		case 'a':
			system("CLS");
			sqcm();
			_getch();
			break;
		case 'B': 
		case 'b':
			system("CLS");
			slcm();
			_getch();
			break;
		case 'C': 
		case 'c':
			system("CLS");
			lopm();
			_getch();
			break;
		case 'D': 
		case 'd':
			system("CLS");
			odarrm();
			_getch();
			break;
		case 'E': 
		case 'e':
			system("CLS");
			tdarrm();
			_getch();
			break;
		case 'F': 
		case 'f':
			system("CLS");
			recursions();
			_getch();
			break;
		case 'G': 
		case 'g':
			system("CLS");
			pointers();
			_getch();
			break;
		case 'H': 
		case 'h':
			system("CLS");
			structs();
			_getch();
			break;
		case 'I': 
		case 'i':
			system("CLS");
			foc();
			_getch();
			break;
		case 'J': 
		case 'j':
			exit(0);
			break;
		}
	} while (pili < 'J' || pili < 'j');

}