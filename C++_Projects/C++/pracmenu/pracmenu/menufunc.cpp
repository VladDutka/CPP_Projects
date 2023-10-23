
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<math.h>
#include<string>
#include<iomanip>
#include <algorithm>
#include<windows.h>
#include<stack>
#include <vector>
#include<fstream>
#include<stdlib.h>
#include "menufunc.h"

using namespace std;
using std::string;
using std::vector;

int rows, cols;
int ray[10][10];
int ray2[10][10];
int rayRow, rayCol;
int lrgst, smllst, key;
int aryDimension;

// GLOBAL VARIABLES
int n; // NUMBER OF STUDENTS
int h; // POSITIONING IN LOOPS
double quizgr; // QUIZ GRADE TOTAL

//TXT BG AND COLOR
void WriteInColor(unsigned short color, string outputString)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	cout << outputString;
}

//GOTOXY
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//BOX
void border()
{
	system("CLS");
	WriteInColor(04, "");
	for (int row = 16; row <= 110; row++)
	{
		gotoxy(row, 2);
		cout << char(178);
		gotoxy(row, 28);
		cout << char(178);
	}
	for (int col = 2; col <= 28; col++)
	{
		gotoxy(16, col);
		cout << char(178);
		gotoxy(110, col);
		cout << char(178);
	}
	WriteInColor(07, "");
}

//FUNCTIONS OF FILE HANDLING, OBJECTS AND CLASSES
void foc1()
{
	ofstream fout;
	char fileN[100];
	char cntnt[100];

	gotoxy(45,5);
	cout << "Enter or Insert File. ";
	gotoxy(50, 7);
	cout << "Enter file name :: ";
	cin >> fileN;

	fout.open(fileN, ios::out);

	gotoxy(50, 9);
	cout << "Enter any word to insert :: ";
	gotoxy(53, 11);
	cin >> cntnt;

	fout << cntnt;
	gotoxy(50, 13);
	cout << "Data inserted successfully..!!\n";

	fout.close();

}

void foc2()
{
	ifstream ifile;
	char s[100], fileN[100];

	gotoxy(45, 5);
	cout << "Read and Display Files";
	gotoxy(50, 7);
	cout << "Enter file name to read :: ";
	gotoxy(78, 7);
	cin >> fileN;

	ifile.open(fileN);

	if (!ifile)
	{
		gotoxy(55, 9);
		cout << "Error in opening file..!!";

		exit(0);
	}

	cout << endl;

	while (ifile.eof() == 0)
	{
		ifile >> s;
		gotoxy(50, 11);
		cout << s << " ";
	}

	cout << endl;
	ifile.close();

}

void foc3()
{
	gotoxy(45,5);
	cout << "Count the number of lines and size of the file. ";
	gotoxy(50, 7);
	cout << "Text File 1 is opened........";
	cout << endl;
	ifstream fin("C:\\Users\\ADMIN\\Desktop\\BSIT 1-1\\Second Semester\\CP 2\\prog files\\pracmenu\\sample.txt"); //opening text file

	int line = 1, word = 1, size; //will not count first word and last line so initial value is 1
	char ch;


	fin.seekg(0, ios::end); //bring file pointer position to end of file
	size = fin.tellg(); //count number of bytes till current postion for file pointer

	fin.seekg(0, ios::beg); //bring position of file pointer to begining of file

	while (fin)
	{
		fin.get(ch);
		if (ch == ' ' || ch == '\n')
			word++;

		if (ch == '\n')
			line++;
	}

	gotoxy(50, 9);
	cout << "No. of Lines = " << line;
	gotoxy(50, 10);
	cout << "No. of Words = " << word;
	gotoxy(50, 11);
	cout << "Size of Text File=" << size << endl;
	fin.close(); //closing file
}

class employee
{
	int roll;
	char name[30];
	float salary;
public:
	employee() { }
	void getData(); // get student data from user
	void displayData(); // display data
};

void employee::getData() {
	cout << "\nEnter Roll No. :: ";
	cin >> roll;
	cin.ignore(); // ignore the newline char inserted when you press enter
	cout << "\nEnter Name :: ";
	cin.getline(name, 30);
	cout << "\nEnter Salary :: ";
	cin >> salary;
}

void employee::displayData() {
	cout << "\nRoll No. :: " << roll << endl;
	cout << "\nName :: " << name << endl;
	cout << "\nSalary :: " << salary << endl;
}

void foc4()
{
	employee e[3]; // array of 3 student objects
	fstream file;
	int i;

	file.open("C:\\Users\\ADMIN\\Desktop\\BSIT 1-1\\Second Semester\\CP 2\\prog files\\pracmenu\\sample.txt", ios::out); // open file for writing
	cout << "\nWriting Employee information to the file :- " << endl;
	cout << "\nEnter 3 employees Details to the File :- " << endl;

	for (i = 0; i < 3; i++)
	{
		e[i].getData();
		// write the object to a file
		file.write((char*)&e[i], sizeof(e[i]));
	}

	file.close(); // close the file

	file.open("C:\\Users\\ADMIN\\Desktop\\BSIT 1-1\\Second Semester\\CP 2\\prog files\\pracmenu\\sample.txt", ios::in); // open file for reading
	cout << "\nReading Student information to the file :- " << endl;

	for (i = 0; i < 3; i++)
	{
		// read an object from a file
		file.read((char*)&e[i], sizeof(e[i]));
		e[i].displayData();
	}

	file.close(); // close the file

}

class biggest
{
private:
	int a, b;
public:
	void input();
	void display();


};
void biggest::input()
{
	cout << "Enter number: ";
	cin >> a;
	cout << "Enter number: ";
	cin >> b;
}
void biggest::display()
{
	if (a > b)
		cout << "Biggest no. :" << a;
	else
		cout << "Biggest no. :" << b;
}

void foc5()
{
	biggest b;
	b.input();
	b.display();
}

class date
{
private:
	int d, m, y;
public:
	void input();
	void display();
};
void date::input()
{
	cout << "Enter a Year: ";
	cin >> y;
	cout << "Enter a Month: ";
	cin >> m;
	cout << "Enter a Day: ";
	cin >> d;
}
void date::display()
{
	cout << "The date today in dd/mm/yyyy format: " << d << " / " << m << " / " << y;
}

void foc6()
{
	date d;
	d.input();
	d.display();
}

//MAINMENU OF FILE HANDLING, OBJECTS AND CLASSES
void foc()
{
	char chFoc;
	do {
		system("CLS");
		border();
		gotoxy(50, 4);
		WriteInColor(04, "********************");
		gotoxy(52, 5);
		WriteInColor(36, " FILE HANDLING MENU ");
		gotoxy(50, 6);
		WriteInColor(04, "********************");
		gotoxy(40, 9);
		WriteInColor(64, "A."); WriteInColor(04, " - Enter / Insert Data into File using File Handling."); WriteInColor(05, "");
		gotoxy(40, 10);
		WriteInColor(64, "B."); WriteInColor(04, " - Read and Display File."); WriteInColor(05, "");
		gotoxy(40, 11);
		WriteInColor(64, "C."); WriteInColor(04, " - Count the # of words, lines and size of the File."); WriteInColor(05, "");
		gotoxy(40, 12);
		WriteInColor(64, "D."); WriteInColor(04, " - Read and Write Employee Details using file handling and classes."); WriteInColor(05, "");
		gotoxy(40, 13);
		WriteInColor(64, "E."); WriteInColor(04, " - Largest number between the two using classes and objects."); WriteInColor(05, "");
		gotoxy(40, 14);
		WriteInColor(64, "F."); WriteInColor(04, " - Enter and Display the date using classe and objects."); WriteInColor(05, "");
		gotoxy(40, 15);
		WriteInColor(64, "G."); WriteInColor(04, " - EXIT"); WriteInColor(05, "");
		gotoxy(40, 18);
		WriteInColor(04, "ENTER YOUR CHOICE. "); WriteInColor(05, "");
		gotoxy(61, 18);
		cin >> chFoc;

		switch (chFoc)
		{
		case 'A':
		case 'a':
			system("CLS"); 
			foc1();
			_getch();
			break;

		case 'B':
		case 'b':
			system("CLS"); 
			foc2();
			_getch();
			break;

		case 'C':
		case 'c':
			system("CLS");
			foc3();
			_getch();
			break;

		case 'D':
		case 'd':
			system("CLS");
			foc4();
			_getch();
			break;

		case 'E':
		case 'e':
			system("CLS"); 
			foc5();
			_getch();
			break;

		case 'F':
		case 'f':
			system("CLS"); 
			foc6();
			_getch();
			break;

		case 'G':
		case 'g':
			break;

		}
	} while (chFoc < 'G' && chFoc < 'g');
}

//FUNCTION OF STRUCT

// STRUCTURES ELEMENTS
struct studentGrade {
	char lname[20];
	char fname[20];
	char mname[20];
	double qz1sc;
	double qz1gr;
	double qz2sc;
	double qz2gr;
	double  exergrade;
	double projgrade;
	double semGrade;
	double equiGrade;
	char remarks[20];
} s[50];

// INPUT STUDENT NAMES
void insert()
{
	gotoxy(50, 4);
	cout << "Enter the number of students: ";
	gotoxy(81, 4);
	cin >> n;
	gotoxy(50, 5);
	cout << "Enter Students Information: " << endl;

	h = 0;
	for (int i = 0; i < n; ++i)
	{
		gotoxy(45, 7 + h);
		cout << "Enter last name: ";
		cin >> s[i].lname;
		gotoxy(45, 8 + h);
		cout << "Enter first name: ";
		cin >> s[i].fname;
		gotoxy(45, 9 + h);
		cout << "Enter middle name: ";
		cin >> s[i].mname;

		h = h + 5;
		cout << endl;
	}
}

// DISPLAY STUDENT INFORMATIONS
void display()
{

	gotoxy(55, 3);
	cout << "List of Student: " << endl << endl;
	cout << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) << "Middle Name" << setw(15) << "Quiz 1 Score" << setw(15) << "Quiz 2 Score" << setw(17) << "Exercises Grade" << setw(17) << "Project Grade" << setw(18) << "Semestral Grade" << setw(18) << "Equivalent Grade" << setw(13) << "Remarks" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << setw(14) << s[i].lname;
		cout << setw(14) << s[i].fname;
		cout << setw(14) << s[i].mname;
		cout << setw(15) << s[i].qz1sc;
		cout << setw(15) << s[i].qz2sc;
		cout << setw(15) << s[i].exergrade;
		cout << setw(15) << s[i].projgrade;
		cout << setw(19) << s[i].semGrade;
		cout << setw(18) << s[i].equiGrade;
		cout << setw(12) << s[i].remarks;

		if (s[i].semGrade >= 75)
			cout << " Passed";
		else
			cout << " Failed";
	}

}

// CALCULATION OF GRADES
void calcu()
{
	h = 0;
	gotoxy(50, 3);
	cout << "Calculation of Grades:";
	for (int i = 0; i < n; ++i)
	{
		gotoxy(45, 6 + h);
		cout << "Last Name: " << s[i].lname;
		gotoxy(45, 7 + h);
		cout << "Quiz 1 Score: ";
		cin >> s[i].qz1sc;
		gotoxy(45, 8 + h);
		cout << "Quiz 2 Score: ";
		cin >> s[i].qz2sc;

		s[i].qz1gr = s[i].qz1sc / 30 * (100);
		gotoxy(45, 10 + h);
		cout << "Quiz 1 Grade: " << s[i].qz1gr;
		s[i].qz2gr = s[i].qz2sc / 30 * (100);
		gotoxy(45, 11 + h);
		cout << "Quiz 2 Grade: " << s[i].qz2gr;

		quizgr = (s[i].qz1gr + s[i].qz2gr) / 2;
		gotoxy(45, 13 + h);
		cout << "Overall Quiz Grade: " << quizgr;

		gotoxy(45, 15 + h);
		cout << "Exercise Grade: ";
		cin >> s[i].exergrade;
		gotoxy(45, 16 + h);
		cout << "Project Grade: ";
		cin >> s[i].projgrade;

		s[i].semGrade = (quizgr + s[i].exergrade + s[i].projgrade) / 3;
		gotoxy(45, 18 + h);
		cout << "Semestral Grade: " << round(s[i].semGrade);
		cout << endl;

		gotoxy(45, 20 + h);
		if (round(s[i].semGrade) <= 100 && round(s[i].semGrade) >= 97)
		{
			s[i].equiGrade = 1.00;
			cout << "Equivalent Grade: " << 1.00;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 96 && round(s[i].semGrade) >= 94)
		{
			s[i].equiGrade = 1.25;
			cout << "Equivalent Grade: " << 1.25;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 93 && round(s[i].semGrade) >= 91)
		{
			s[i].equiGrade = 1.50;
			cout << "Equivalent Grade: " << 1.50;

			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 90 && round(s[i].semGrade) >= 88)
		{
			s[i].equiGrade = 1.75;
			cout << "Equivalent Grade: " << 1.75;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 87 && round(s[i].semGrade) >= 85)
		{
			s[i].equiGrade = 2.00;
			cout << "Equivalent Grade: " << 2.00;

			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 84 && round(s[i].semGrade) >= 82)
		{
			s[i].equiGrade = 2.25;
			cout << "Equivalent Grade: " << 2.25;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 81 && round(s[i].semGrade) >= 79)
		{
			s[i].equiGrade = 2.50;
			cout << "Equivalent Grade: " << 2.50;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) <= 80 && round(s[i].semGrade) >= 76)
		{
			s[i].equiGrade = 2.75;
			cout << "Equivalent Grade: " << 2.75;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) == 75)
		{
			s[i].equiGrade = 3.00;
			cout << "Equivalent Grade: " << 3.00;
			gotoxy(45, 20 + h);
			cout << "Remarks: Passed";
		}
		else if (round(s[i].semGrade) < 74)
		{
			s[i].equiGrade = 5.00;
			cout << "Equivalent Grade: " << 5.00;
			gotoxy(45, 20 + h);
			cout << "Remarks: Failed";
		}
		else
		{
			s[i].equiGrade = 5.00;
			gotoxy(45, 20 + h);
			cout << "Incomplete";
			gotoxy(45, 21 + h);
			cout << "Remarks: Failed";
		}
		h = h + 17;

	}
}

// SEARCH A CERTAIN STUDENT USING LAST NAME
void searchInfo()
{
	char searchLastn[20];
	gotoxy(50, 4);
	cout << "Search Information of Student";
	gotoxy(50, 6);
	cout << "Enter student last name to search: ";
	cin >> searchLastn;
	cout << endl;
	cout << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) << "Middle Name" << setw(15) << "Quiz 1 Score" << setw(15) << "Quiz 2 Score" << setw(17) << "Exercises Grade" << setw(17) << "Project Grade" << setw(18) << "Semestral Grade" << setw(18) << "Equivalent Grade" << setw(13) << "Remarks" << endl;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(s[i].lname, searchLastn) == 0)
		{
			cout << endl;
			cout << setw(14) << s[i].lname;
			cout << setw(14) << s[i].fname;
			cout << setw(14) << s[i].mname;
			cout << setw(15) << s[i].qz1sc;
			cout << setw(15) << s[i].qz2sc;
			cout << setw(15) << s[i].exergrade;
			cout << setw(15) << s[i].projgrade;
			cout << setw(19) << s[i].semGrade;
			cout << setw(18) << s[i].equiGrade;
			cout << setw(12) << s[i].remarks;

			if (s[i].semGrade >= 75)
				cout << " Passed";
			else
				cout << " Failed";
		}
	}
}

// COMPARE TWO VARIABLES FOR SORTING
bool cmp(studentGrade a, studentGrade b)
{
	if (a.equiGrade != b.equiGrade)
		return a.equiGrade < b.equiGrade;
	else
		return 0;
}

// SORTING STUDENTS BY THEIR GRADES
void sortInfo()
{
	gotoxy(47, 1);
	cout << "Students Information in Descending Order" << endl;
	cout << endl;
	sort (s, s+n,cmp);
	cout << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) << "Middle Name" << setw(15) << "Quiz 1 Score" << setw(15) << "Quiz 2 Score" << setw(17) << "Exercises Grade" << setw(17) << "Project Grade" << setw(18) << "Semestral Grade" << setw(18) << "Equivalent Grade" << setw(13) << "Remarks" << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		cout << setw(14) << s[i].lname;
		cout << setw(14) << s[i].fname;
		cout << setw(14) << s[i].mname;
		cout << setw(15) << s[i].qz1sc;
		cout << setw(15) << s[i].qz2sc;
		cout << setw(15) << s[i].exergrade;
		cout << setw(15) << s[i].projgrade;
		cout << setw(19) << s[i].semGrade;
		cout << setw(18) << s[i].equiGrade;
		cout << setw(12) << s[i].remarks;

		if (s[i].semGrade >= 75)
			cout << "Passed";
		else
			cout << "Failed";
	}
}


//MAINMENU OF STRUCTURES
int structs()
{
	system("cls");
	char selStruct;
	do
	{
		system("cls");
		gotoxy(50, 3);
		cout << "PROGRAMMING 2";
		gotoxy(47, 4);
		cout << "Students Grades";
		gotoxy(50, 6);
		cout << "A. Students Information";
		gotoxy(50, 7);
		cout << "B. Display students information";
		gotoxy(50, 8);
		cout << "C. Input total score";
		gotoxy(50, 9);
		cout << "D. Search students";
		gotoxy(50, 10);
		cout << "E. Sort records";
		gotoxy(50, 11);
		cout << "F. Exit";
		gotoxy(50, 15);
		cout << "Enter your choice: ";
		cin >> selStruct;
		switch (selStruct)
		{
		case 'A':
		case 'a':
			system("cls");
			insert();
			_getch();
			break;

		case 'B':
		case 'b':
			system("cls");
			display();
			_getch();
			break;

		case 'C':
		case 'c':
			system("cls");
			calcu();
			_getch();
			break;

		case 'D':
		case 'd':
			system("cls");
			searchInfo();
			_getch();
			break;

		case 'E':
		case 'e':
			system("cls");
			sortInfo();
			_getch();
			break;

		case 'F':
		case 'f':
			break;
		}
	} while (selStruct < 'F' && selStruct < 'f');
	return 0;
}


//FUNCTIONS OF POINTERS
//swapping numbers
void swpPntrs(int a, int b)
{
	int* c, * d;
	int temp;

	c = &a;
	d = &b;

	gotoxy(40, 11);
	cout << "Original Version";
	gotoxy(43, 13);
	cout << "First Number: " << a << " and Second Number: " << b;
	
	temp = *c;
	*c = *d;
	*d = temp;

	gotoxy(40, 15);
	cout << "Swapped Version";
	gotoxy(43, 17);
	cout << "First Number: " << a << " and Second Number: " << b;

}
//counting length of string
void strlngthPntrs()
{
	int a;
	gotoxy(40,5);
	cout << "COUNT THE NUMBER OF STRING" << endl;
	a = 0;
	char word[50], * p;

	p = word;

	gotoxy(40,7);
	cout << "Enter a word: ";
	gotoxy(54,7);
	cin >> p;

	while (*p != '\0')
	{
		a++;
		p++;
	}

	gotoxy(40, 9);
	cout << "String length: " << a;
	_getch();
}

//reverse of the string
string rvrstrngPntrs(char word[20])
{
	char a = 'a';
	char b = 'b';
	char* first = &a;
	char* last = &b;
	for (int i = 0; i < (strlen(word) / 2); i++)
	{
		first[0] = word[i];
		last[0] = word[strlen(word) - 1 - i];
		word[i] = *last;
		word[strlen(word) - 1 - i] = *first;
	}
	return word;
}

//count vowels and consonants
void vowsandconsPntrs()
{
	char word[100], * p, vwls, cnsnts;
	cnsnts = vwls = 0;
	gotoxy(40,5);
	cout << "Count of Vowels and Consonants.";
	gotoxy(40, 7);
	cout << "Enter a word: ";
	gotoxy(54, 7);
	cin >> word;

	p = word;

	while (*p != '\0')
	{
		if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U')
			++vwls;
		else if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
			++cnsnts;
		++p;
	}

	gotoxy(40, 9);
	printf("Vowels: %d\n", vwls);
	gotoxy(40, 10);
	printf("Consonants: %d\n", cnsnts);
}

//add 2 num using call reference
long addnumPntrs(long* numb1, long* numb2)
{
	long total;
	total = *numb1 + *numb2;
	return total;
}

//MAINMENU OF POINTERS
void pointers()
{
	system("cls");
	char chpntrs;
	do
	{
		int a, b;
		system("cls");
		border();
		gotoxy(52, 4);
		WriteInColor(011, "********************");
		gotoxy(57, 5);
		WriteInColor(73, "POINTERS MENU");
		gotoxy(52, 6);
		WriteInColor(011, "********************");
		gotoxy(35, 10);
		WriteInColor(814, "A."); WriteInColor(014, " - Swap two numbers."); WriteInColor(013, "");
		gotoxy(35, 11);
		WriteInColor(814, "B."); WriteInColor(014, " - Calculate the lenght of the string."); WriteInColor(013, "");
		gotoxy(35, 12);
		WriteInColor(814, "C."); WriteInColor(014, " - Display the reverse of a string."); WriteInColor(013, "");
		gotoxy(35, 13);
		WriteInColor(814, "D."); WriteInColor(014, " - Count the numbers of vowel and consonants."); WriteInColor(013, "");
		gotoxy(35, 14);
		WriteInColor(814, "E."); WriteInColor(014, " - Add two integers using call reference."); WriteInColor(013, "");
		gotoxy(35, 15);
		WriteInColor(814, "F."); WriteInColor(014, " - Exit."); WriteInColor(013, "");

		gotoxy(35, 17);
		WriteInColor(02, "Enter your choice: "); WriteInColor(013, "");
		gotoxy(55, 17);
		cin >> chpntrs;

		switch (chpntrs)
		{
		case 'A':
		case 'a':
			system("cls");
			gotoxy(40, 5);
			cout << "SWAP VALUES";
			gotoxy(40, 7);
			cout << "First number: ";
			gotoxy(55, 7);
			cin >> a;
			gotoxy(40, 9);
			cout << "Second number: ";
			gotoxy(55, 9);
			cin >> b;
			swpPntrs(a, b);
			_getch();
			break;
		case 'B':
		case 'b':
			system("cls");
			strlngthPntrs();
			_getch();
			break;
		case 'C':
		case 'c':
			system("cls");
			char words[20];
			gotoxy(40, 5);
			cout << "Reversing the string.";
			gotoxy(40, 7);
			cout << "Enter a word: ";
			gotoxy(54, 7);
			cin >> words;
			gotoxy(40, 9);
			cout << "Reversed Version: " << rvrstrngPntrs(words);
			_getch();
			break;
		case 'D':
		case 'd':
			system("cls");
			vowsandconsPntrs();
			_getch();
			break;
		case 'E':
		case 'e':
			system("cls");
			long fnum, snum, total;
			gotoxy(40, 5);
			cout << "Addition using call reference.";
			gotoxy(40, 7);
			cout << "Enter first number: ";
			gotoxy(60, 7);
			cin >> fnum;
			gotoxy(40, 9);
			cout << "Enter second number: ";
			gotoxy(61, 9);
			cin >> snum;
			total = addnumPntrs(&fnum, &snum);
			gotoxy(40, 11);
			cout << "The sum is: " << total;
			_getch();
			break;
		case 'F':
		case 'f':
			break;
		}
	} while (chpntrs < 'F' && chpntrs < 'f');
	_getch();
}

//FUNCTIONS OF RECURS
// Variables for lexicographical order
int lword; // holds the length of a word
string word; // value of the word
vector<string> str;
int pow_set;

//lexicog function to sort the word
void lex(string word, vector<string>& str, int lword, int pow_set)
{
	int i, j;
	for (i = 0; i < pow_set; i++) {
		string x;
		for (j = 0; j < lword; j++) {
			if (i & 1 << j) {
				x = x + word[j];
			}
		}
		if (i != 0)
			str.push_back(x);
	}
}
//lexicog function to enter a word
void lexicog()
{
	gotoxy(40,5);
	cout << "Lexicographical Order: ";
	gotoxy(40,7);
	cout << "Enter a word: ";
	cin >> word;
	lword = word.length();
	pow_set = pow(2, lword);
	lex(word, str, lword, pow_set);
	sort(str.begin(), str.end());
	gotoxy(35, 9);
	cout << "Answer: ";
	gotoxy(43, 9);
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

//Variables for Reversing Stacks
stack<char> stck;
string ns;
char stck1, stck2, stck3, stck4, stck5;
//stack function p2
void insert_at_bottom(char x) //will insert element under the stack
{

	if (stck.size() == 0)
		stck.push(x);

	else
	{

		char a = stck.top();
		stck.pop();
		insert_at_bottom(x);

		stck.push(a);
	}
}
//stack function p1
void reverse() // will reverse the stack
{
	if (stck.size() > 0)
	{
		char x = stck.top();
		stck.pop();
		reverse();
		insert_at_bottom(x);
	}
}
//reversing stacks
void revStacks()
{
	gotoxy(40,5);
	cout << "Reversing th stacks.";
	gotoxy(40,7);
	cout << "Enter a letter for the elements of stack:";
	gotoxy(40, 9);
	cout << "1st Stack: ";
	cin >> stck1;
	stck.push(stck1);
	gotoxy(40, 10);
	cout << "2nd Stack: ";
	cin >> stck2;
	stck.push(stck2);
	gotoxy(40, 11);
	cout << "3rd Stack: ";
	cin >> stck3;
	stck.push(stck3);
	gotoxy(40, 12);
	cout << "4th Stack: ";
	cin >> stck4;
	stck.push(stck4);
	gotoxy(40, 13);
	cout << "5th Stack: ";
	cin >> stck5;
	stck.push(stck5);

	gotoxy(40, 15);
	cout << "Original Version of Stack"; // display the stacks
	gotoxy(40, 17);
	cout << stck1 << " " << stck2 << " "
		<< stck3 << " " << stck4 << " "
		<< stck5 << endl;

	reverse(); //Reversing the stack
	gotoxy(40, 20);
	cout << "Reversed Version of Stack" << endl;
	while (!stck.empty()) //stored values of stack
	{
		char p = stck.top();
		stck.pop();
		ns += p;
	}

	//display of reversed stack
	gotoxy(40, 21);
	cout << ns[4] << " " << ns[3] << " " << ns[2] << " "
		<< ns[1] << " " << ns[0] << endl;
}

//variable for recaman
int z;
//recaman sequence function
int recaman(int z)
{
	int recRay[50];
	// First term of the sequence is always 0
	recRay[0] = 0;
	cout << recRay[0] << ", ";
	// Fill remaining terms using recursive
	// formula.
	for (int i = 1; i < z; i++)
	{
		int curr = recRay[i - 1] - i;
		int j;
		for (j = 0; j < i; j++)
		{
			// If arr[i-1] - i is negative or
			// already exists.
			if ((recRay[j] == curr) || curr < 0)
			{
				curr = recRay[i - 1] + i;
				break;
			}
		}

		recRay[i] = curr;
		cout << recRay[i] << ", ";
	}
	return 0;
}

//variable for palindrome func
int numPal;
//singleNum
int oneDigit(int num)
{
	return (num >= 0 && num < 10);
}
//palindrome func 1
bool isPalUtil(int num, int* dupNum)
{
	if (oneDigit(num)) //comparing of digits
		return (num == (*dupNum) % 10);

	if (!isPalUtil(num / 10, dupNum))
		return false;

	*dupNum /= 10;

	return (num % 10 == (*dupNum) % 10);
}
//palindrome func 2
int isPal(int num)
{

	if (num < 0) //neg or pos
		num = -num;

	int* dupNum = new int(num);

	return isPalUtil(num, dupNum);
}
//palindrome func 3
int numbPalin()
{
	char deci;
	gotoxy(40, 5);
	cout << "Palindrome";
	gotoxy(40, 7);
	cout << "Enter a number to check if it is  a Palindrome or not. ";
	gotoxy(40, 9);
	cout << "Number: ";
	gotoxy(48, 9);
	cin >> numPal;
	gotoxy(43,11);
	isPal(numPal) ? cout << ("Yes") : cout << ("No");
	gotoxy(40,13);
	cout << "Try another one? Press Y for yes and N for No.";
	gotoxy(43, 15);
	cin >> deci;
	if (deci == 'Y')
	{
		system("cls");
		numbPalin();
	}
	else if (deci == 'N')
		return 0;
	else
		return 0;
}

//product recursion function
int recurPrdct(int a1, int b2)
{
	// if x is less than
	// y swap the numbers
	if (a1 < b2)
		return recurPrdct(b2, a1);
	else if (b2 != 0)
		return (a1 + recurPrdct(a1, b2 - 1));
	else
		return 0;
}
//display of product and input of numbers
void recurPrdctdsply()
{
	int a1, b2;
	gotoxy(40,5);
	cout << "Product";
	gotoxy(40,7);
	cout << "Enter two numbers to get the product. " << endl;
	gotoxy(40,9);
	cout << "Number: ";
	gotoxy(48,9);
	cin >> a1;
	gotoxy(40,10);
	cout << "Number: ";
	gotoxy(48, 10);
	cin >> b2;
	gotoxy(40, 12);
	cout << "Product: " << recurPrdct(a1, b2);
}

//MAINMENU OF RECURSIONS
void recursions()
{
	system("cls");
	char chrecur;
	do {
		system("cls");
		border();
		gotoxy(52, 4);
		WriteInColor(011, "********************");
		gotoxy(57, 5);
		WriteInColor(73, "RECURSIVE MENU");
		gotoxy(52, 6);
		WriteInColor(011, "********************");
		gotoxy(42, 10);
		WriteInColor(814, "A."); WriteInColor(014, " - Lexicographical Order."); WriteInColor(013, "");
		gotoxy(42, 11);
		WriteInColor(814, "B."); WriteInColor(014, " - Reverse a Stack."); WriteInColor(013, "");
		gotoxy(42, 12);
		WriteInColor(814, "C."); WriteInColor(014, " - Recaman Sequence."); WriteInColor(013, "");
		gotoxy(42, 13);
		WriteInColor(814, "D."); WriteInColor(014, " - Number Palindrome."); WriteInColor(013, "");
		gotoxy(42, 14);
		WriteInColor(814, "E."); WriteInColor(014, " - Product of two numbers."); WriteInColor(013, "");
		gotoxy(42, 15);
		WriteInColor(814, "F."); WriteInColor(014, " - Exit."); WriteInColor(013, "");
		
		gotoxy(42, 17);
		WriteInColor(02, "Enter your choice: "); WriteInColor(013, "");
		gotoxy(62, 17);
		cin >> chrecur;

		switch (chrecur)
		{
		case 'A':
		case 'a':
			system("cls");
			lexicog();
			_getch();
			break;
		case 'B':
		case 'b':
			system("cls");
			revStacks();
			_getch();
			break;
		case 'C':
		case 'c':
			system("cls");
			gotoxy(40, 5);
			cout << "Recaman Sequence";
			gotoxy(40, 7);
			cout << "Enter a number to get a Recaman Sequence: ";
			cin >> z;
			gotoxy(40, 9);
			recaman(z);
			_getch();
			break;
		case 'D':
		case 'd':
			system("cls");
			numbPalin();
			_getch();
			break;
		case 'E':
		case 'e':
			system("cls");
			recurPrdctdsply();
			_getch();
			break;
		case 'F':
		case 'f':
			break;
		}
	} while (chrecur < 'F' && chrecur < 'f');
	_getch();
}

//FUNTIONS OF MENU E
void ar1(int ray[], int numb)
{
	int a = 10;
	for (int i = 0; i < numb; i++, a++)
	{
		gotoxy(35, a);
		cout << "Number [" << i << "]: ";
		cin >> ray[i];
	}
}
void ar2(int ray[], int numb)
{
	for (int i = 0; i < numb; i++)
		cout << ray[i] << " ";
}
void ar3(int ray[], int numb, int srch)
{
	int crt = 0;
	int pos;
	for (int i = 0; i < aryDimension; i++)
	{
		if (ray[i] == srch)
		{
			crt = 1;
			pos = i + 1;
			break;

		}
	}
	if (crt == 0)
	{
		gotoxy(35, 12);
		cout << "Element not found.";
	}
	else
	{
		gotoxy(35, 12);
		cout << "Element " << srch << " is in the array." << endl;
		gotoxy(35, 14);
		cout << "Element is in position " << pos;
	}
}
void ar4(int ray[], int numb)
{
	int end;
	gotoxy(35, 7);
	for (int i = 0; i < numb; i++)

		cout << ray[i] << " ";
	gotoxy(35, 10);
	cout << "Sorted in ascending order: ";

	for (int i = 0; i < numb; i++)
	{
		for (int g = i + 1; g < numb; g++)
		{
			if (ray[i] > ray[g])
			{
				end = ray[i];
				ray[i] = ray[g];
				ray[g] = end;
			}
		}
	}
	for (int f = 0; f < numb; f++)
	{
		cout << ray[f] << " ";
	}
}
void ar5(int ray[], int numb, int dilit)
{
	int y = 0, f = 0;
	for (int i = 0; i < numb; i++)
	{
		if (ray[i] == dilit)
		{
			ray[i] = 0;
			y = 1;
		}
		if (y == 1)
		{
			break;
		}
	}

	if (y == 0)
	{
		gotoxy(35, 10);
		cout << dilit;
		cout << " is not in the dimension of the array.";
	}
	if (y == 1)
	{
		for (int i = 0; i < numb; i++)
		{
			if (ray[i] != 0)
			{
				ray[f] = ray[i];
				f++;
			}
		}

		aryDimension = numb - 1;

		for (int i = 0; i < aryDimension; i++)
		{
			gotoxy(35, 10);
			cout << ray[i] << " ";
		}
		gotoxy(35, 12);
		cout << "Succesfully deleted.";
		gotoxy(35, 14);
		cout << "Current size of array: " << aryDimension;
	}
}
void ar6(int ray[], int numb)
{
	int  i, elmnt, pstn;

	for (i = 0; i < numb; i++)
		cout << ray[i] << " ";

	gotoxy(35, 10);
	cout << "Enter Element to Insert: ";
	cin >> elmnt;
	gotoxy(35, 12);
	cout << "Enter the number of position: ";
	cin >> pstn;

	for (i = numb; i >= pstn; i--)
	{
		if (i == pstn)
			ray[i - 1] = elmnt;
	}
	gotoxy(35, 14);
	cout << "The New version of Array is:";
	gotoxy(35, 16);
	for (int d = 0; d < aryDimension; ++d) {
		cout << ray[d] << "  ";
	}

}
void ar7(int ray[], int lrgst)
{
	int big = ray[0];

	for (int b = 0; b < lrgst; b++)
	{
		if (big < ray[b])
		{
			big = ray[b];
		}
	}
	gotoxy(35, 7);
	cout << "Largest number: " << big;
}
void ar8(int ray[], int smllst)
{
	int smol = ray[0];

	for (int s = 0; s < smllst; s++)
	{
		if (smol > ray[s])
		{
			smol = ray[s];
		}
	}
	gotoxy(35, 7);
	cout << "Smallest number: " << smol;
}
void ar9(int ray[], int numb)
{
	gotoxy(35, 7);
	for (int i = 0; i < numb; i++)
	{
		cout << ray[i] << " ";
	}
	gotoxy(35, 10);
	cout << "The even numbers are: ";
	for (int i = 0; i < numb; i++)
	{
		if (ray[i] % 2 == 0)
		{
			cout << ray[i] << " ";
		}
	}
}
void ar10(int ray[], int numb)
{
	gotoxy(35, 7);
	for (int i = 0; i < numb; i++)
	{
		cout << ray[i] << " ";
	}
	gotoxy(35, 10);
	cout << "The odd numbers are: ";
	for (int i = 0; i < numb; i++)
	{
		if (ray[i] % 2 != 0)
		{
			cout << ray[i] << " ";
		}
	}
}
void ar11(int ray[], int numb)
{
	gotoxy(35, 10);
	for (int i = 0; i < numb; i++)
	{
		cout << ray[i] << " ";
	}
	int ttl = 0;
	for (int i = 0; i < numb; i++)
	{
		ttl += ray[i];
	}
	gotoxy(35, 12);
	cout << "The sum of all elements is: " << ttl;

}
int ar12(int ray[], int numb)
{
	int tiny = ray[0], v = 0;

	for (int i = 0; i < numb; i++)
	{
		if (ray[i] < tiny)
		{
			tiny = ray[i];
			v = i;
		}

	}
	return v;
}
int ar13(int ray[], int numb)
{
	int giant = ray[0], k = 0;

	for (int i = 0; i < numb; i++)
	{
		if (ray[i] > giant)
		{
			giant = ray[i];
			k = i;
		}

	}
	return k;
}
void ar14(int ray[], int numb)
{
	gotoxy(35, 7);
	for (int i = 0; i < numb; i++)
	{
		cout << ray[i] << " ";
	}

	int ttl = 0;
	for (int i = 0; i < numb; i++)
	{
		ttl += ray[i] * ray[i];
	}
	gotoxy(35, 10);
	cout << "The sum of all elements is: " << ttl;

}
void ar15(int ray[], int ray2[], int numb)
{
	gotoxy(35, 7);
	cout << "The value of original array is: ";
	for (int i = 0; i < numb; i++)
	{
		cout << ray[i] << " ";
	}

	for (int i = 0; i < numb; i++)
	{
		ray2[i] = ray[i];
	}
	gotoxy(35, 9);
	cout << "The copied version is: ";
	for (int i = 0; i < numb; i++)
	{
		cout << ray2[i] << " ";
	}
}
int ar16(int ray2[], int numb, int srch)
{
	int starting = 0;
	int ending = numb - 1;
	int mid;

	bool found = false;

	while (starting <= ending && !found)
	{
		mid = (starting + ending) / 2;

		if (ray2[mid] == srch)
			found = true;
		else
			if (ray2[mid] > srch)
				ending = mid - 1;
			else
				starting = mid + 1;
	}
	gotoxy(35, 10);
	if (found)
		cout << srch << " is in position of the arrange number found in index: " << mid;
	else
		return -1;
}
void ar17(int ray2[], int numb)
{
	for (int i = 0; i < numb; i++)
		cout << ray2[i] << " ";

	gotoxy(35, 11);
	cout << "The Insertion sort version: ";

	int i, loc;
	int temp;
	for (i = 1; i < numb; i++)

		if (ray2[i] < ray2[i - 1])
		{
			temp = ray2[i];
			loc = i;
			do
			{
				ray2[loc] = ray2[loc - 1];
				loc--;
			} while (loc > 0 && ray2[loc - 1] > temp);
			ray2[loc] = temp;
		}

	for (int i = 0; i < numb; i++)
		cout << ray2[i] << " ";

}

//MAINMENU OF TWO D ARRAYS
void tdarrm()
{
	int elmnt, srch, dilit, key;
	char choiced;
	system("CLS");
	do {

		border();
		gotoxy(52, 4);
		WriteInColor(011, "********************");
		gotoxy(57, 5);
		WriteInColor(73, "ARRAY MENU");
		gotoxy(52, 6);
		WriteInColor(011, "********************");
		gotoxy(35, 8);
		WriteInColor(814, "A."); WriteInColor(014, " - Input elements of the array."); WriteInColor(013, "");
		gotoxy(35, 9);
		WriteInColor(814, "B."); WriteInColor(014, " - Display the elements of the array."); WriteInColor(013, "");
		gotoxy(35, 10);
		WriteInColor(814, "C."); WriteInColor(014, " - Search elements from the array."); WriteInColor(013, "");
		gotoxy(35, 11);
		WriteInColor(814, "D."); WriteInColor(014, " - Sort the elements of the array."); WriteInColor(013, "");
		gotoxy(35, 12);
		WriteInColor(814, "E."); WriteInColor(014, " - Delete element from the array."); WriteInColor(013, "");
		gotoxy(35, 13);
		WriteInColor(814, "F."); WriteInColor(014, " - Update / Edit the element of the array."); WriteInColor(013, "");
		gotoxy(35, 14);
		WriteInColor(814, "G."); WriteInColor(014, " - Largest element in the array."); WriteInColor(013, "");
		gotoxy(35, 15);
		WriteInColor(814, "H."); WriteInColor(014, " - Smallest element in the array."); WriteInColor(013, "");
		gotoxy(35, 16);
		WriteInColor(814, "I."); WriteInColor(014, " - All even numbers in the array."); WriteInColor(013, "");
		gotoxy(35, 17);
		WriteInColor(814, "J."); WriteInColor(014, " - All odd numbers in the array."); WriteInColor(013, "");
		gotoxy(35, 18);
		WriteInColor(814, "K."); WriteInColor(014, " - Sum of all the elements of the array."); WriteInColor(013, "");
		gotoxy(35, 19);
		WriteInColor(814, "L."); WriteInColor(014, " - Index of the smallest element of the array."); WriteInColor(013, "");
		gotoxy(35, 20);
		WriteInColor(814, "M."); WriteInColor(014, " - Index of the largest element of the array."); WriteInColor(013, "");
		gotoxy(35, 21);
		WriteInColor(814, "N."); WriteInColor(014, " - Sum of all the squares of the array."); WriteInColor(013, "");
		gotoxy(35, 22);
		WriteInColor(814, "O."); WriteInColor(014, " - Copy of the elements of the array."); WriteInColor(013, "");
		gotoxy(35, 23);
		WriteInColor(814, "P."); WriteInColor(014, " - Binary search algorithm. "); WriteInColor(013, "");
		//Using the binary search algorithm, create a program that will search for an element of a 1 - D array."
		gotoxy(35, 24);
		WriteInColor(814, "Q."); WriteInColor(014, " - Ascending order using Insertion sort."); WriteInColor(013, "");
		//Create a function that will sort the integer elements of a 1-D array in ascending order using insertion sort algorithm.
		gotoxy(35, 25);
		WriteInColor(814, "R."); WriteInColor(014, " - Exit."); WriteInColor(013, "");
		gotoxy(35, 27);
		WriteInColor(02, "Enter your choice: "); WriteInColor(013, "");
		gotoxy(55, 27);
		cin >> choiced;


		switch (choiced)
		{

		case 'A':
		case 'a':
			system("CLS");
			gotoxy(35, 5);
			cout << "Input elements of the array." << endl;
			arA();
			_getch();
			break;

		case 'B':
		case 'b':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display the elements of the array." << endl;
			arB();
			_getch();
			break;

		case 'C':
		case 'c':
			system("CLS");
			gotoxy(35, 5);
			cout << "Search elements from the array." << endl;
			gotoxy(35, 7);
			cout << "Enter the element you want to search: ";
			cin >> srch;
			gotoxy(35, 10);
			arC(srch);
			_getch();
			break;

		case 'D':
		case 'd':
			system("CLS");
			gotoxy(35, 5);
			cout << "Sort the elements of the array.";
			arD();
			_getch();
			break;

		case 'E':
		case 'e':
			system("CLS");
			gotoxy(35, 5);
			cout << "Delete element from the array.";
			arE(rows, cols);
			_getch();
			break;

		case 'F':
		case 'f':
			system("CLS");
			gotoxy(35, 5);
			cout << "Update / Edit the element of the array." << endl;
			gotoxy(35, 11);
			cout << "Enter row: ";
			cin >> rows;
			gotoxy(35, 12);
			cout << "Enter column: ";
			cin >> cols;
			gotoxy(35, 13);
			cout << "What Element?: ";
			cin >> elmnt;
			arF(elmnt);
			_getch();
			break;

		case 'G':
		case 'g':
			system("CLS");
			gotoxy(35, 5);
			cout << "Largest element in the array.";
			arG(ray, lrgst);
			_getch();
			break;

		case 'H':
		case 'h':
			system("CLS");
			gotoxy(35, 5);
			cout << "Smallest element in the array.";
			arH(ray, smllst);
			_getch();
			break;

		case 'I':
		case 'i':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display all even numbers in the array.";
			arI(ray);
			_getch();
			break;

		case 'J':
		case 'j':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display all odd numbers in the array." << endl;
			arJ(ray);
			_getch();
			break;

		case 'K':
		case 'k':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display the sum of all the elements of the array.";
			gotoxy(35, 7);
			cout << "The sum of all the elements is: ";
			arK(ray);
			_getch();
			break;

		case 'L':
		case 'l':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display the index of the smallest element of the array.";
			arL(ray);
			_getch();
			break;

		case 'M':
		case 'm':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display the index of the largest element of the array.";
			arM(ray);
			_getch();
			break;

		case 'N':
		case 'n':
			system("CLS");
			gotoxy(35, 5);
			cout << "Display the sum of all the squares of the array.";
			arN(ray);
			_getch();
			break;

		case 'O':
		case 'o':
			system("CLS");
			gotoxy(35, 5);
			cout << "Create a function that will copy the elements of the array.";
			arO(ray, ray2);
			_getch();
			break;

		case 'P':
		case 'p':
			system("CLS");
			gotoxy(35, 5);
			cout << "Using the binary search algorithm, create a program that ";
			gotoxy(35, 6);
			cout << "will search for an element of a 1-D array.";
			gotoxy(35, 8);
			cout << "! THE ARRAY ENTERED MUST BE SORTED !";
			gotoxy(35, 10);
			cout << "Enter the element you want to search: ";
			cin >> srch;
			arP(ray2, srch);
			_getch();
			break;

		case 'Q':
		case 'q':
			system("CLS");
			gotoxy(35, 5);
			cout << "Create a function that will sort the integer elements of";
			gotoxy(35, 6);
			cout << " a 1-D array in ascending order using the insertion sort algorithm.";
			gotoxy(35, 8);
			cout << "Current value of the array: ";
			arQ(ray2);
			_getch();
			break;

		case 'R':
		case 'r':
			break;
		}

	} while (choiced < 'R' && choiced < 'r');
	//_getch();
}

//FUNCTIONS OF MENU D
void arA()
{
	gotoxy(35, 7);
	cout << "Enter the number of rows: ";
	cin >> rayRow;
	gotoxy(35, 9);
	cout << "Enter the number of columns: ";
	cin >> rayCol;
	int arActrl = 11;

	for (int rows = 0; rows < rayRow; rows++)
	{

		for (int cols = 0; cols < rayCol; cols++, arActrl++)
		{
			gotoxy(35, arActrl);
			cout << "Enter a value for row [" << rows << "] and column [" << cols << "]: ";
			cin >> ray[rows][cols];
		}

	}
}
void arB()
{
	int arActrl = 8;
	for (int rows = 0; rows < rayRow; rows++)
	{
		for (int cols = 0; cols < rayCol; cols++, arActrl++)
		{
			gotoxy(35, arActrl);
			cout << "The value of row [" << rows << "] " << "and column [" << cols << "]: " << ray[rows][cols];
		}

	}
	int arActrl2 = 20;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();
}
void arC(int srch)
{
	int crt = 0;
	int pos, neg;
	for (int rows = 0; rows < rayRow; rows++)
	{

		for (int cols = 0; cols < rayCol; cols++)
		{
			if (ray[rows][cols] == srch)
			{
				crt = 1;
				pos = rows;
				neg = cols;
				break;
			}
		}
		if (crt == 0)
		{
			gotoxy(35, 12);
			cout << "Element not found.";
		}
		else
		{
			gotoxy(35, 12);
			cout << "Element " << srch << " is in the array." << endl;
			gotoxy(35, 14);
			cout << "Element is in row [" << pos << "] and column [" << neg << "].";
		}
	}
}
void arD()
{
	// ORIG ARRAY
	gotoxy(35, 7);
	int arActrl2 = 9;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();


	gotoxy(35, 16);
	cout << "Sorted in ascending order: ";

	int x;

	for (int k = 0; k < rayRow; k++)
	{
		for (int m = 0; m < rayCol; m++)
		{
			x = m + 1;
			for (int i = k; i < rayRow; i++)
			{
				for (int j = x; j < rayCol; j++)
				{
					if (ray[k][m] > ray[i][j]) //swapping
					{
						int temp = ray[k][m];
						ray[k][m] = ray[i][j];
						ray[i][j] = temp;
					}
				}
				x = 0;
			}
		}
	}

	for (int i = 0; i < rayRow; i++) //sorted version
	{
		for (int j = 0; j < rayCol; j++)
		{
			cout << ray[i][j] << " ";
		}
	}
}
void arE(int rows, int cols)
{
	int arActrl2 = 7;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();
	gotoxy(35, 12);
	cout << "Enter row-position to delete: ";
	cin >> rows;
	gotoxy(35, 13);
	cout << "Enter column-position to delete: ";
	cin >> cols;

	for (int i = rows; i < rayRow; i++)
	{
		for (int j = cols; j < rayCol; j++)
		{
			ray[rows][cols] = ray[rows + 1][cols + 1];
		}
	}

	gotoxy(35, 15);
	cout << "Succesfully deleted.";
	int arActrl3 = 17;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl3++)
	{
		gotoxy(35, arActrl3);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();
}
void arF(int elmnt)
{

	int arActrl2 = 7;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();

	ray[rows][cols] = elmnt;

	gotoxy(35, 15);
	cout << "Successfully Edited!";

	int arActrl5 = 17;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		gotoxy(35, arActrl5);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++, arActrl5++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
}
void arG(int ray[10][10], int lrgst)
{
	int big = INT_MIN;

	for (int b = 0; b < rayRow; b++)
	{
		for (int g = 0; g < rayCol; g++)
		{
			if (ray[b][g] > big)
			{
				big = ray[b][g];
			}
		}
	}
	gotoxy(35, 7);
	cout << "Largest number: " << big;
}
void arH(int ray[10][10], int smllst)
{
	int smol = INT_MAX;

	for (int s = 0; s < rayRow; s++)
	{
		for (int t = 0; t < rayCol; t++)
		{
			if (ray[s][t] < smol)
			{
				smol = ray[s][t];
			}
		}
	}
	gotoxy(35, 7);
	cout << "Smallest number: " << smol;
}
void arI(int ray[10][10])
{
	int arActrl2 = 9;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();

	gotoxy(35, 14);
	cout << "The even numbers are: ";
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		//gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			if (ray[ctr3][ctr4] % 2 == 0)
			{
				cout << ray[ctr3][ctr4] << "\t";
			}
		}
		cout << endl;
	}
}
void arJ(int ray[10][10])
{
	int arActrl2 = 9;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();

	gotoxy(35, 14);
	cout << "The odd numbers are: ";
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		//gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			if (ray[ctr3][ctr4] % 2 != 0)
			{
				cout << ray[ctr3][ctr4] << "\t";
			}
		}
		cout << endl;
	}
}
void arK(int ray[10][10])
{
	int arActrl2 = 9;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();

	int ttl = 0;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{

			ttl += ray[ctr3][ctr4];
		}
	}
	gotoxy(35, 12);
	cout << "The sum of all elements is: " << ttl;
}
void arL(int ray[10][10])
{
	int tiny = ray[0][0], v = 0, h = 0;

	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			if (ray[ctr3][ctr4] < tiny)
			{
				tiny = ray[ctr3][ctr4];
				v = ctr3;
				h = ctr4;
			}
		}

	}
	gotoxy(35, 8);
	cout << tiny << "is found in index [" << v << "] and [" << h << "] ";
}
void arM(int ray[10][10])
{
	int giant = ray[0][0], n = 0, t = 0;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			if (ray[ctr3][ctr4] > giant)
			{
				giant = ray[ctr3][ctr4];
				n = ctr3;
				t = ctr4;
			}
		}

	}
	gotoxy(35, 8);
	cout << giant << " is found in index [" << n << "] and [" << t << "] ";
}
void arN(int ray[10][10])
{
	int arActrl2 = 9;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();

	int ttl = 0;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++)
	{
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{

			ttl += ray[ctr3][ctr4] * ray[ctr3][ctr4];
		}
	}
	gotoxy(35, 12);
	cout << "The sum of all elements is: " << ttl;
}
void arO(int ray[10][10], int ray2[10][10])
{
	gotoxy(35, 7);
	cout << "The value of original array is: ";
	int arActrl2 = 9;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();
	// EQUATING	
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			ray2[ctr3][ctr4] = ray[ctr3][ctr4];
		}
	}
	//COPIED
	gotoxy(35, 14);
	cout << "The copied version is: ";
	int arActrl8 = 17;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl8++)
	{
		gotoxy(35, arActrl8);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray2[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();

}
void arP(int ray2[10][10], int srch)
{
	int starting = 0;
	int ending1 = rayRow - 1;
	int ending2 = rayCol - 1;
	int mid1, mid2;

	bool found = false;

	while (starting <= ending1 && !found || ending2 && !found)
	{
		mid1 = (starting + ending1) / 2;
		mid2 = (starting + ending2) / 2;

		if (ray2[mid1][mid2] == srch)
			found = true;
		else
			if (ray2[mid1][mid2] > srch)
			{
				ending1 = mid1 - 1;
				ending2 = mid2 - 1;
			}
			else
			{
				starting = mid1 + 1;
				starting = mid2 + 1;
			}
	}
	gotoxy(35, 13);
	if (found)
		cout << srch << " is in position of the arrange number found in in row [" << mid1 << "] and column [" << mid2 << "] ";
	else
		cout << "Not found!";
}
void arQ(int ray2[10][10])
{
	int arActrl2 = 10;
	for (int ctr3 = 0; ctr3 < rayRow; ctr3++, arActrl2++)
	{
		gotoxy(35, arActrl2);
		for (int ctr4 = 0; ctr4 < rayCol; ctr4++)
		{
			cout << ray2[ctr3][ctr4] << "\t";
		}
		cout << endl;
	}
	cin.get();


	gotoxy(35, 13);
	cout << "The Insertion sort version: ";

	int i, h, loc1, loc2;
	int temp;
	for (i = 1; i < rayRow; i++)
	{
		for (h = 1; h < rayCol; h++)
		{

			if (ray2[i][h] < ray2[i - 1][h - 1])
			{
				temp = ray2[i][h];
				loc1 = i;
				loc2 = h;
				do
				{
					ray2[loc1][loc2] = ray2[loc1 - 1][loc2 - 1];
					loc1--;
					loc2--;
				} while (loc1 && loc2 > 0 && ray2[loc1 - 1][loc2 - 1] > temp);
				ray2[loc1][loc2] = temp;
			}
		}
	}

	for (int loc1 = 0; loc1 < rayRow; loc1++)
	{
		for (int loc2 = 0; loc2 < rayCol; loc2++)
		{
			cout << ray2[loc1][loc2] << " ";
		}
	}

}

//MAINMENU OF ONE D ARRAY
void odarrm()
{
	int aryDimension;
	int ray[15];
	int ray2[15];
	ray[15] = ray2[15];
	int numb, srch, dilit;
	char choiceor;

	system("cls");
	do {

		border();
		gotoxy(47, 27);
		cout << "RENDON, GEOFFREY CABRERA    BSIT 1-1";
		gotoxy(55, 2);
		cout << "ARRAY MENU";
		gotoxy(35, 4);
		cout << "A - Input elements of the array.";
		gotoxy(35, 5);
		cout << "B - Display the elements of the array.";
		gotoxy(35, 6);
		cout << "C - Search elements from the array.";
		gotoxy(35, 7);
		cout << "D - Sort the elements of the array.";
		gotoxy(35, 8);
		cout << "E - Delete element from the array.";
		gotoxy(35, 9);
		cout << "F - Update / Edit the element of the array.";
		gotoxy(35, 10);
		cout << "G - Largest element in the array.";
		gotoxy(35, 11);
		cout << "H - Smallest element in the array.";
		gotoxy(35, 12);
		cout << "I - Display all even numbers in the array.";
		gotoxy(35, 13);
		cout << "J - Display all odd numbers in the array.";
		gotoxy(35, 14);
		cout << "K - Display the sum of all the elements of the array.";
		gotoxy(35, 15);
		cout << "L - Display the index of the smallest element of the array.";
		gotoxy(35, 16);
		cout << "M - Display the index of the largest element of the array.";
		gotoxy(35, 17);
		cout << "N - Display the sum of all the squares of the array.";
		gotoxy(35, 18);
		cout << "O - Create a function that will copy the elements of the array.";
		gotoxy(35, 19);
		cout << "P - Using the binary search algorithm, create a program that";
		gotoxy(39, 20);
		cout << " will search for an element of a 1 - D array.";
		gotoxy(35, 21);
		cout << "Q - Create a function that will sort the integer elements of a";
		gotoxy(39, 22);
		cout << " 1-D array in ascending order using insertion sort algorithm.";
		gotoxy(35, 23);
		cout << "R - Exit.";
		gotoxy(35, 24);
		cout << "Enter your choice: ";
		gotoxy(55, 24);
		cin >> choiceor;


		switch (choiceor)
		{

		case 'A':
		case 'a':
			system("cls");
			gotoxy(35, 5);
			cout << "Input elements of the array." << endl;
			gotoxy(35, 7);
			cout << "Enter the number of elements you want: ";
			cin >> numb;
			aryDimension = numb;
			ar1(ray, numb);
			_getch();
			break;

		case 'B':
		case 'b':
			system("cls");
			gotoxy(35, 5);
			cout << "Display the elements of the array." << endl;
			aryDimension = numb;
			gotoxy(40, 7);
			ar2(ray, numb);
			_getch();
			break;

		case 'C':
		case 'c':
			system("cls");
			gotoxy(35, 5);
			cout << "Search elements from the array." << endl;
			gotoxy(35, 7);
			cout << "Enter the element you want to search: ";
			cin >> srch;
			gotoxy(35, 10);
			ar3(ray, numb, srch);
			_getch();
			break;

		case 'D':
		case 'd':
			system("cls");
			gotoxy(35, 5);
			cout << "Sort the elements of the array.";
			ar4(ray, aryDimension);
			_getch();
			break;

		case 'E':
		case 'e':
			system("cls");
			gotoxy(35, 5);
			cout << "Delete element from the array.";
			gotoxy(35, 7);
			cout << "Enter the element you want to delete: ";
			cin >> dilit;
			ar5(ray, aryDimension, dilit);
			_getch();
			break;

		case 'F':
		case 'f':
			system("cls");
			gotoxy(35, 5);
			cout << "Update / Edit the element of the array." << endl;
			gotoxy(35, 7);
			ar6(ray, numb);
			_getch();
			break;

		case 'G':
		case 'g':
			system("cls");
			gotoxy(35, 5);
			cout << "Largest element in the array.";
			ar7(ray, aryDimension);
			_getch();
			break;

		case 'H':
		case 'h':
			system("cls");
			gotoxy(35, 5);
			cout << "Smallest element in the array.";
			ar8(ray, aryDimension);
			_getch();
			break;

		case 'I':
		case 'i':
			system("cls");
			gotoxy(35, 5);
			cout << "Display all even numbers in the array.";
			ar9(ray, aryDimension);
			_getch();
			break;

		case 'J':
		case 'j':
			system("cls");
			gotoxy(35, 5);
			cout << "Display all odd numbers in the array." << endl;
			ar10(ray, aryDimension);
			_getch();
			break;

		case 'K':
		case 'k':
			system("cls");
			gotoxy(35, 5);
			cout << "Display the sum of all the elements of the array.";
			gotoxy(35, 7);
			cout << "The sum of all the elements is: ";
			ar11(ray, aryDimension);
			_getch();
			break;

		case 'L':
		case 'l':
			system("cls");
			gotoxy(35, 5);
			cout << "Display the index of the smallest element of the array.";
			gotoxy(35, 7);
			cout << ar12(ray, aryDimension);
			_getch();
			break;

		case 'M':
		case 'm':
			system("cls");
			gotoxy(35, 5);
			cout << "Display the index of the largest element of the array.";
			gotoxy(35, 7);
			cout << ar13(ray, aryDimension);
			_getch();
			break;

		case 'N':
		case 'n':
			system("cls");
			gotoxy(35, 5);
			cout << "Display the sum of all the squares of the array.";
			ar14(ray, aryDimension);
			_getch();
			break;

		case 'O':
		case 'o':
			system("cls");
			gotoxy(35, 5);
			cout << "Create a function that will copy the elements of the array.";
			ar15(ray, ray2, aryDimension);
			_getch();
			break;

		case 'P':
		case 'p':
			system("cls");
			gotoxy(35, 5);
			cout << "Using the binary search algorithm, create a program that ";
			gotoxy(35, 6);
			cout << "will search for an element of a 1-D array.";
			gotoxy(35, 8);
			cout << "! THE ARRAY ENTERED MUST BE SORTED !";
			gotoxy(35, 10);
			cout << "Enter the element you want to search: ";
			cin >> srch;
			ar16(ray2, aryDimension, srch);
			_getch();
			break;

		case 'Q':
		case 'q':
			system("cls");
			gotoxy(35, 5);
			cout << "Create a function that will sort the integer elements of";
			gotoxy(35, 6);
			cout << " a 1-D array in ascending order using the insertion sort algorithm.";
			gotoxy(35, 8);
			cout << "Current value of the array: ";
			ar17(ray2, aryDimension);
			_getch();
			break;

		case 'R':
		case 'r':
			exit(0);
			break;
		}

	} while (choiceor < 'R' && choiceor < 'r');


	_getch();
}

//FUNCTIONS OF MENU C
void loph()
{
	char looph;
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "--------------------------------" << endl;
		gotoxy(35, 5);
		cout << "NUMBER TRIANGLE PATTERN" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "--------------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> looph;

		switch (looph)
		{
		case 'A':
		case 'a':
			system("CLS");
		{
			int aw, bw, hrow1 = 7;
			for (aw = 5; aw >= 1; aw--, hrow1++)
			{
				gotoxy(35, hrow1);
				for (bw = 1; bw <= aw; bw++)
					cout << aw;
				cout << endl;
			}
			_getch();
			break;
		}
		case 'B':
		case 'b':
			system("CLS");
		{
			int ad, bd, hrow2;
			ad = 5, bd = 1, hrow2 = 7;
			while (ad >= 1)
			{
				gotoxy(35, hrow2);
				while (bd <= ad)
				{
					cout << ad;
					bd++;
				}
				bd = 1;
				ad--;
				hrow2++;
				cout << endl;
			}
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			int ar, br, hrow3;
			ar = 5, br = 1, hrow3 = 7;
			do
			{
				gotoxy(35, hrow3);
				do
				{
					cout << ar;
					br++;
				} while (br <= ar);

				br = 1;
				ar--;
				hrow3++;
				cout << endl;
			} while (ar >= 1);
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (looph < 'D' && looph < 'd');
}
void lopg(char loopg)
{

	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "------------------------------" << endl;
		gotoxy(35, 5);
		cout << "STAR TRIANGLE PATTERN" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "------------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loopg;

		switch (loopg)
		{
		case 'A':
		case 'a':
			system("CLS");
		{
			int aq, bq, grow1 = 7;
			for (aq = 1; aq <= 5; aq++, grow1++)
			{
				gotoxy(35, grow1);
				for (bq = 1; bq <= aq; bq++)
				{
					cout << "*";
				}
				cout << endl;
			}
			_getch();
			break;
		}
		case 'B':
		case 'b':
			system("CLS");
		{
			int as, bs, grow2;
			as = 1, bs = 1, grow2 = 7;
			while (as <= 5)
			{
				gotoxy(35, grow2);
				while (bs <= as)
				{
					cout << "*";
					bs++;
				}
				bs = 1;
				as++;
				grow2++;
				cout << endl;
			}
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			int ae, be, grow3;
			ae = 1, be = 1, grow3 = 7;
			do
			{
				gotoxy(35, grow3);
				do
				{
					cout << "*";
					be++;
				} while (be <= ae);

				be = 1;
				ae++;
				grow3++;
				cout << endl;
			} while (ae <= 5);
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (loopg < 'D' && loopg < 'd');
}
void lopf()
{
	char loopf;
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "--------------------------------" << endl;
		gotoxy(35, 5);
		cout << "ALL POSITIVE NUMBERS IN 5 INPUTS" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "--------------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loopf;

		switch (loopf)
		{
		case 'A':
		case 'a':
			system("CLS");
		{
			int no = 1, ctri = 1, frow1 = 7, subrow = 14;
			for (ctri = 1; ctri <= 5; ctri++, frow1++, subrow++)
			{
				gotoxy(35, frow1);
				cout << "Enter a number: ";
				cin >> no;

				if (no > 0)
				{
					gotoxy(35, subrow);
					cout << "Number: " << no << endl;
				}
				else if (no < 0)
				{
					gotoxy(35, subrow);
					cout << "Negative number." << endl;
				}
				else
				{
					gotoxy(35, subrow);
					cout << "Neutral number." << endl;
				}
			}
			_getch();
			break;
		}
		case 'B': 
		case 'b':
			system("CLS");
		{
			int noa = 1, ctrj = 1, frow2 = 7, subrow2 = 13;
			while (ctrj <= 5)
			{
				gotoxy(35, frow2);
				cout << "Enter a number: ";
				cin >> noa;

				if (noa > 0)
				{
					gotoxy(35, subrow2);
					cout << "Number: " << noa << endl;
				}
				else if (noa < 0)
				{
					gotoxy(35, subrow2);
					cout << "Negative number." << endl;
				}
				else
				{
					gotoxy(35, subrow2);
					cout << "Neutral number." << endl;
				}
				ctrj++;
				frow2++;
				subrow2++;
			}
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			int nob = 1, ctrk = 1, frow3 = 7, subrow3 = 13;
			do
			{
				gotoxy(35, frow3);
				cout << "Enter a number: ";
				cin >> nob;

				if (nob > 0)
				{
					gotoxy(35, subrow3);
					cout << "Number: " << nob << endl;
				}
				else if (nob < 0)
				{
					gotoxy(35, subrow3);
					cout << "Negative number." << endl;
				}
				else
				{
					gotoxy(35, subrow3);
					cout << "Neutral number." << endl;
				}
				ctrk++;
				frow3++;
				subrow3++;
			} while (ctrk <= 5);
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (loopf < 'D' && loopf < 'd');
}
void lope(char loope)
{
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "-----------------------------" << endl;
		gotoxy(35, 5);
		cout << "EVEN NUMBER FROM 1 - 10" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "-----------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loope;

		switch (loope)
		{
		case 'A': 
		case 'a':
			system("CLS");
		{
			
			int ctrf, erow1 = 7;
			for (ctrf = 2; ctrf <= 10; ctrf = ctrf + 2, erow1++)
			{
				gotoxy(35, erow1);
				cout << ctrf << endl;
			}
			_getch();
			break;
		}
		case 'B':
		case 'b':
			system("CLS");
		{
			int ctrg, erow2 = 7;
			ctrg = 2;
			while (ctrg <= 10)
			{
				gotoxy(35, erow2);
				cout << ctrg << endl;
				ctrg = ctrg + 2;
				erow2++;
			}
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			int ctrh, erow3 = 7;
			ctrh = 2;
			do
			{
				gotoxy(35, erow3);
				cout << ctrh << endl;
				ctrh = ctrh + 2;
				erow3++;
			} while (ctrh <= 10);
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (loope < 'D' && loope < 'd');
}
void lopd()
{
	char loopd;
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "-----------------------------" << endl;
		gotoxy(35, 5);
		cout << "FACTORIAL OF THE NUMBER" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "-----------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loopd;

		switch (loopd)
		{
		case 'A':
		case 'a':
			system("CLS");
		{
			signed long int numb, ii, fa = 1;
			gotoxy(33, 5);
			cout << "Enter a number: ";
			cin >> numb;
			for (ii = 1; ii <= numb; ii++)
				fa = fa * ii;
			gotoxy(35, 7);
			cout << "Factorial of " << numb << " is: " << fa << endl;
			_getch();
			break;
		}
		case 'B':
		case 'b':
			system("CLS");
		{
			signed long int numbe, ft = 1;
			int is;
			gotoxy(33, 5);
			cout << "Enter a number: ";
			cin >> numbe;
			is = 1;
			while (is <= numbe)
			{
				ft = ft * is;
				is = is++;
			}
			gotoxy(35, 7);
			cout << "Factorial of " << numbe << " is: " << ft << endl;
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			signed long int numbee, fr = 1;
			int id;
			gotoxy(33, 5);
			cout << "Enter a number: ";
			cin >> numbee;
			id = 1;
			do
			{
				fr = fr * id;
				id = id++;
			} while (id <= numbee);
			gotoxy(35, 7);
			cout << "Factorial of " << numbee << " is: " << fr << endl;
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (loopd < 'D' && loopd < 'd');
}
void lopc(char loopc)
{
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "-----------------------------" << endl;
		gotoxy(35, 5);
		cout << "NUMBERS N DOWN TO 1" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "-----------------------------" << endl << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loopc;

		switch (loopc)
		{
		case 'A': 
		case 'a':
			system("CLS");
		{
			int n, i, crow1 = 7;
			gotoxy(33, 5);
			cout << "Enter a number: ";
			cin >> n;
			for (i = n; i >= 1; i--, crow1++)
			{
				gotoxy(35, crow1);
				cout << i << endl;
			}
			_getch();
			break;
		}
		case 'B':
		case 'b':
			system("CLS");
		{
			int n1, i1, crow2 = 7;
			gotoxy(33, 5);
			cout << "Enter a number: ";
			cin >> n1;
			i1 = n1;
			while (i1 >= 1)
			{
				gotoxy(35, crow2);
				cout << i1 << endl;
				i1--;
				crow2++;
			}
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			int n2, i2, crow3 = 7;
			gotoxy(33, 5);
			cout << "Enter a number: ";
			cin >> n2;

			i2 = n2;
			do
			{
				gotoxy(35, crow3);
				cout << i2 << endl;
				i2--;
				crow3++;
			} while (i2 >= 1);
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (loopc < 'D' && loopc < 'd');
}
void lopb()
{
	char loopb;
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "-----------------------------" << endl;
		gotoxy(35, 5);
		cout << "NUMBERS 1 - 10" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl;
		gotoxy(30, 12);
		cout << "-----------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loopb;

		switch (loopb)
		{
		case 'A':
		case 'a':
			system("CLS");
		{
			int ctrc, brow1 = 7;
			for (ctrc = 1; ctrc <= 10; ctrc++, brow1++)
			{
				gotoxy(35, brow1);
				cout << ctrc << endl;
			}
			_getch();
			break;
		}
		case 'B':
		case 'b':
			system("CLS");
		{
			int ctrd, brow2 = 7;
			ctrd = 1;
			while (ctrd <= 10)
			{
				gotoxy(35, brow2);
				cout << ctrd << endl;
				ctrd = ctrd++;
				brow2++;
			}
			_getch();
			break;
		}
		case 'C':
		case 'c':
			system("CLS");
		{
			int ctre, brow3 = 7;
			ctre = 1;
			do
			{
				gotoxy(35, brow3);
				cout << ctre << endl;
				ctre = ctre++;
				brow3++;
			} while (ctre <= 10);
			_getch();
			break;
		}
		case 'D':
		case 'd':
			break;
		}
	} while (loopb < 'D' && loopb < 'd');
}
void lopa(char loopa)
{
	do
	{
		system("CLS");
		gotoxy(30, 4);
		cout << "-----------------------------" << endl;
		gotoxy(35, 5);
		cout << "PRINTS THE NAME 5X" << endl;
		gotoxy(35, 7);
		cout << "CHOOSE A LOOP" << endl << endl;
		gotoxy(35, 8);
		cout << "A. For Loop" << endl;
		gotoxy(35, 9);
		cout << "B. While Loop" << endl;
		gotoxy(35, 10);
		cout << "C. Do While Loop" << endl;
		gotoxy(35, 11);
		cout << "D. Back to Main Menu" << endl << endl;
		gotoxy(30, 12);
		cout << "-----------------------------" << endl;
		gotoxy(37, 14);
		cout << "CHOICE: ";
		gotoxy(45, 14);
		cin >> loopa;

		switch (loopa)
		{
		case 'A':
		case 'a':
			system("CLS");
		{
			int ctr, arow1 = 7;
			for (ctr = 1; ctr <= 5; ctr++, arow1++)
			{
				gotoxy(35, arow1);
				cout << "Geoffrey" << endl;
			}
			_getch();
			break;
		}
		case 'B': 
		case 'b':
			system("CLS");
		{
			int ctra, arow2 = 7;
			ctra = 1;
			while (ctra <= 5)
			{
				gotoxy(35, arow2);
				cout << "Geoffrey" << endl;
				ctra = ctra++;
				arow2++;
			}
			_getch();
			break;
		}
		case 'C': 
		case 'c':
			system("CLS");
		{
			int ctrb, arow3 = 7;
			ctrb = 1;
			do
			{
				gotoxy(35, arow3);
				cout << "Geoffrey" << endl;
				ctrb = ctrb++;
				arow3++;
			} while (ctrb <= 5);
			_getch();
			break;
		}

		case 'D':
		case 'd':
			break;
		}
	} while (loopa < 'D' && loopa < 'd');
}

//MAINMENU OF ITERATION
void lopm()
{
	char choicet;
	do {
		system("CLS");
		border();
		gotoxy(50, 4);
		WriteInColor(05, "********************");
		gotoxy(52, 5);
		WriteInColor(05, " ITERATION MENU ");
		gotoxy(50, 6);
		WriteInColor(05, "********************");
		gotoxy(45, 9);
		WriteInColor(45, "A."); WriteInColor(07, " - PRINTS THE NAME 5X"); WriteInColor(02, "");
		gotoxy(45, 10);
		WriteInColor(45, "B."); WriteInColor(07, " - NUMBERS 1 - 10"); WriteInColor(02, "");
		gotoxy(45, 11);
		WriteInColor(45, "C."); WriteInColor(07, " - NUMBERS N DOWN TO 1"); WriteInColor(02, "");
		gotoxy(45, 12);
		WriteInColor(45, "D."); WriteInColor(07, " - FACTORIAL OF THE NUMBER"); WriteInColor(02, "");
		gotoxy(45, 13);
		WriteInColor(45, "E."); WriteInColor(07, " - EVEN NUMBERS FROM 1 - 10"); WriteInColor(02, "");
		gotoxy(45, 14);
		WriteInColor(45, "F."); WriteInColor(07, " - ALL POSITIVE NUMBERS IN 5 INPUTS"); WriteInColor(02, "");
		gotoxy(45, 15);
		WriteInColor(45, "G."); WriteInColor(07, " - STAR PATTERN"); WriteInColor(02, "");
		gotoxy(45, 16);
		WriteInColor(45, "H."); WriteInColor(07, " - NUMBER PATTERN"); WriteInColor(02, "");
		gotoxy(45, 17);
		WriteInColor(45, "I."); WriteInColor(07, " - EXIT"); WriteInColor(02, "");
		gotoxy(45, 19);
		WriteInColor(05, "ENTER YOUR CHOICE. "); WriteInColor(02, "");
		gotoxy(66, 19);
		cin >> choicet;

		switch (choicet)
		{
		case 'A': 
		case 'a':
			system("CLS");

			char loopa;
			loopa = '\0';
			lopa(loopa); //no return with param
			break;

		case 'B': 
		case 'b':
			system("CLS");
			lopb(); //no return no param
			break;

		case 'C':
		case 'c':
			system("CLS");
			char loopc;
			loopc = '\0';
			lopc(loopc); //no return with param
			break;


		case 'D':
		case 'd':
			system("CLS");
			lopd(); //no return no param
			break;

		case 'E': 
		case 'e':
			system("CLS");
			char loope;
			loope = '\0';
			lope(loope); //no return with param
			break;

		case 'F':
		case 'f':
			system("CLS");
			lopf(); //no return no param
			break;

		case 'G': 
		case 'g':
			system("CLS");
			char loopg;
			loopg = '\0';
			lopg(loopg); //no return with param
			break;

		case 'H': 
		case 'h':
			system("CLS");
			loph(); //no return no param
			break;
		case 'I':
		case 'i':
			break;
		}
	} while (choicet < 'I' && choicet < 'i');
}

//FUNCTIONS OF MENU B
void zero()
{
	int numm;
	gotoxy(25, 8);
	cout << "Enter a number: ";
	cin >> numm;
	gotoxy(25, 10);
	if (numm > 0)
		cout << "The number is positive." << endl;
	else if (numm < 0)
		cout << "The number is negative." << endl;
	else
		cout << "The number is zero and it is neutral." << endl;
}
void threenum(int nu1, int nu2, int nu3)
{
	gotoxy(25, 12);
	if (nu1 > nu2 && nu1 > nu3)
		cout << nu1 << " is the largest number among the three." << endl;
	else if (nu2 > nu1 && nu2 > nu3)
		cout << nu2 << " is the largest number among the three." << endl;
	else
		cout << nu3 << " is the largest number among the three." << endl;
}
void twonum(int n1, int n2)
{
	gotoxy(25, 11);
	if (n1 > n2)
		cout << n1 << " is the largest number. " << endl;
	else
		cout << n2 << " is the largest number. " << endl;
}
int sales()
{
	int sNum, untSold, untPrice, totSales;
	char sName[20];
	gotoxy(25, 8);
	cout << "Salesman Number: ";
	cin >> sNum;
	gotoxy(25, 9);
	cout << "Salesman Name: ";
	cin >> sName;
	gotoxy(25, 10);
	cout << "Number of Units Sold: ";
	cin >> untSold;
	gotoxy(25, 11);
	cout << "Unit Price: ";
	cin >> untPrice;

	totSales = untSold * untPrice;
	return totSales;

}
int posneg()
{
	int numb;
	gotoxy(25, 8);
	cout << "Input a number: ";
	cin >> numb;
	gotoxy(25, 10);
	if (numb > 0)
		cout << "The number is positive.";
	else
		cout << "The number is negative.";
	return 0;
}
void oe(int num)
{
	gotoxy(25, 10);
	if (num % 2 == 0)
		cout << num << " is even number. ";
	else
		cout << num << " is odd number. ";
}
void pmf(int prel, int midt, int fin)
{

	float avee;

	avee = (prel + midt + fin) / 3;
	//return avee;
	gotoxy(25, 12);
	cout << "The average is " << avee << endl;
	gotoxy(25, 13);
	if (avee <= 100 && avee >= 97)
		cout << "The equivalent of the average is 1.0" << endl;
	else if (avee <= 96 && avee >= 94)
		cout << "The equivalent of the average is 1.25" << endl;
	else if (avee <= 93 && avee >= 91)
		cout << "The equivalent of the average is 1.50" << endl;
	else if (avee <= 90 && avee >= 88)
		cout << "The equivalent of the average is 1.75" << endl;
	else if (avee <= 87 && avee >= 85)
		cout << "The equivalent of the average is 2.0" << endl;
	else if (avee <= 84 && avee >= 82)
		cout << "The equivalent of the average is 2.25" << endl;
	else if (avee <= 81 && avee >= 79)
		cout << "The equivalent of the average is 2.50" << endl;
	else if (avee <= 78 && avee >= 76)
		cout << "The equivalent of the average is 2.75" << endl;
	else if (avee == 75)
		cout << "The equivalent of the average is 3.0" << endl;
	else
		cout << "You failed!" << endl;
}

//MAINMENU OF SELECTION
void slcm()
{
	char choicel;
	do {
		system("CLS");
		border();
		gotoxy(50, 4);
		WriteInColor(04, "********************");
		gotoxy(52, 5);
		WriteInColor(36, " SELECTION MENU ");
		gotoxy(50, 6);
		WriteInColor(04, "********************");
		gotoxy(45, 9);
		WriteInColor(64, "A."); WriteInColor(04, " - AVERAGE AND EQUIVALENTS"); WriteInColor(05, "");
		gotoxy(45, 10);
		WriteInColor(64, "B."); WriteInColor(04, " - ODD OR EVEN"); WriteInColor(05, "");
		gotoxy(45, 11);
		WriteInColor(64, "C."); WriteInColor(04, " - POSITIVE OR NEGATIVE"); WriteInColor(05, "");
		gotoxy(45, 12);
		WriteInColor(64, "D."); WriteInColor(04, " - TOTAL SALES AND COMMISION"); WriteInColor(05, "");
		gotoxy(45, 13);
		WriteInColor(64, "E."); WriteInColor(04, " - LARGEST NUMBER BETWEEN THE 2"); WriteInColor(05, "");
		gotoxy(45, 14);
		WriteInColor(64, "F."); WriteInColor(04, " - LARGEST NUMBER AMONG THE 3"); WriteInColor(05, "");
		gotoxy(45, 15);
		WriteInColor(64, "G."); WriteInColor(04, " - POSITIVE, NEGATIVE OR NEUTRAL"); WriteInColor(05, "");
		gotoxy(45, 16);
		WriteInColor(64, "H."); WriteInColor(04, " - EXIT"); WriteInColor(05, "");
		gotoxy(45, 18);
		WriteInColor(04, "ENTER YOUR CHOICE. "); WriteInColor(05, "");
		gotoxy(66, 18);
		cin >> choicel;

		switch (choicel)
		{
		case 'A':
		case 'a':
			system("CLS"); //funtion with arguments and does not return a value
			int prel, midt, fin;
			gotoxy(25, 8);
			cout << "Prelim grade: ";
			gotoxy(40, 8);
			cin >> prel;
			gotoxy(25, 9);
			cout << "Midterm grade: ";
			gotoxy(41, 9);
			cin >> midt;
			gotoxy(25, 10);
			cout << "Finals grade: ";
			gotoxy(40, 10);
			cin >> fin;
			pmf(prel, midt, fin);

			_getch();
			break;

		case 'B': 
		case 'b':
			system("CLS"); //funtion with arguments and does not return a value
			int num;
			gotoxy(25, 8);
			cout << "Input the number: ";
			cin >> num;
			oe(num);
			_getch();
			break;

		case 'C': 
		case 'c':
			system("CLS"); //funtion without argument and returns a value
			posneg();
			_getch();
			break;

		case 'D': 
		case 'd':
			system("CLS"); //funtion without argument and returns a value
			int totSales;
			totSales = sales();
			gotoxy(25, 13);
			cout << "The total sales is " << totSales << endl;
			gotoxy(25, 14);
			if (totSales <= 10000)
				cout << "The commission is 10%" << endl;
			else if (totSales <= 15000)
				cout << "The commission is 15%" << endl;
			else if (totSales <= 20000)
				cout << "The commission is 20%" << endl;
			else if (totSales > 20000)
				cout << "The commission is 30%" << endl;
			_getch();
			break;

		case 'E': 
		case 'e':
			system("CLS"); //funtion with arguments and does not return a value
			int n1, n2;
			gotoxy(25, 8);
			cout << "Enter a number: ";
			cin >> n1;
			gotoxy(25, 9);
			cout << "Enter a number: ";
			cin >> n2;
			twonum(n1, n2);
			_getch();
			break;

		case 'F': 
		case 'f':
			system("CLS"); //funtion with arguments and does not return a value
			int nu1, nu2, nu3;
			gotoxy(25, 8);
			cout << "Enter a number: ";
			cin >> nu1;
			gotoxy(25, 9);
			cout << "Enter a number: ";
			cin >> nu2;
			gotoxy(25, 10);
			cout << "Enter a number: ";
			cin >> nu3;
			threenum(nu1, nu2, nu3);
			_getch();
			break;

		case 'G':
		case 'g':
			system("CLS"); //funtion without argument and does not return a value
			zero();
			_getch();
			break;

		case 'H': 
		case 'h':
			//exit
			break;

		}
	} while (choicel < 'H' && choicel < 'h');
}

//FUNCTIONS OF MENU A
void sqac(int numbe1)
{
	gotoxy(25, 8);
	cout << "SQUARE AND CUBE";
	int square, cube;
	square = numbe1 * numbe1;
	gotoxy(32, 12);
	cout << "Square value: " << square << endl;
	cube = (numbe1 * numbe1 * numbe1);
	gotoxy(32, 13);
	cout << "Cube value: " << cube << endl;
}
void gpnp()
{
	gotoxy(25, 8);
	cout << "GROSS PAY AND NET PAY";
	int grossPay, empNumber;
	float netPay;
	char empName[20], lName[20];
	gotoxy(32, 10);
	cout << "Employee Number: ";
	gotoxy(50, 10);
	cin >> empNumber;
	gotoxy(32, 11);
	cout << "Employee First Name: ";
	gotoxy(54, 11);
	cin >> empName;
	gotoxy(32, 12);
	cout << "Employee Last Name: ";
	gotoxy(53, 12);
	cin >> lName;

	float numOfHours, ratePerHour;
	gotoxy(32, 13);
	cout << "Number of Hours: ";
	gotoxy(50, 13);
	cin >> numOfHours;
	gotoxy(32, 14);
	cout << "Rate per Hours: ";
	gotoxy(49, 14);
	cin >> ratePerHour;

	grossPay = numOfHours * ratePerHour;
	gotoxy(32, 16);
	cout << "The value of Gross Pay is: " << grossPay << endl;

	netPay = grossPay - (grossPay * 0.1);
	gotoxy(32, 17);
	cout << "The value of Net Pay is: " << netPay << endl;
}
float temp(float celsius)
{
	gotoxy(25, 8);
	cout << "CELSIUS AND FAHRENHEIT";
	float farenheit;

	farenheit = (celsius * 9 / 5) + 32;
	return farenheit;

}
void arcr()
{
	gotoxy(25, 8);
	cout << "AREA AND CIRCUMFERENCE";
	int diameter;
	float pi = 3.14;
	float radius, circ, areac;
	gotoxy(32, 10);
	cout << "Input the diameter. " << endl;
	gotoxy(54, 10);
	cin >> diameter;
	circ = pi * diameter;
	gotoxy(32, 11);
	cout << "The circumference of the circle is " << setprecision(2) << circ << endl;
	radius = diameter / 2;
	areac = pi * (radius * radius);
	gotoxy(32, 12);
	cout << "The area of the circle is " << setprecision(2) << areac << endl;

}
int ave()
{
	gotoxy(25, 8);
	cout << "AVERAGE";
	float numb1, numb2, numb3, numb4, total;
	float average;
	gotoxy(32, 10);
	cout << "Enter the four numbers: " << endl;
	gotoxy(32, 11);
	cin >> numb1;
	gotoxy(32, 12);
	cin >> numb2;
	gotoxy(32, 13);
	cin >> numb3;
	gotoxy(32, 14);
	cin >> numb4;
	total = numb1 + numb2 + numb3 + numb4;
	gotoxy(32, 16);
	cout << "The total of the number is " << total;
	average = total / 4;

	return average;
}
void swap(char var1, char var2)
{
	gotoxy(25, 8);
	cout << "SWAPPED VALUES";
	char var3;

	var3 = var1;
	var1 = var2;
	var2 = var3;
	gotoxy(32, 13);
	cout << "Swapped values: ";
	gotoxy(32, 14);
	cout << "Variable 1: " << var1;
	gotoxy(33, 15);
	cout << "Variable 2: " << var2;
}
int ap(int l, int w)
{
	gotoxy(25, 8);
	cout << "AREA AND PERIMETER";
	int perim, area;

	perim = 2 * (l + w);
	gotoxy(32, 13);
	cout << "The value of the perimeter is " << perim << endl;

	area = l * w;
	gotoxy(32, 14);
	cout << "The value of the area is " << area << endl;
	return 0;
}
void roots()
{
	gotoxy(25, 8);
	cout << "ROOTS OF QUADRATIC EQUATION" << endl;
	int a, b, c, x1, x2;
	gotoxy(32, 10);
	cout << "Enter the value of a: ";
	gotoxy(55, 10);
	cin >> a;
	gotoxy(32, 11);
	cout << "Enter the value of b: ";
	gotoxy(55, 11);
	cin >> b;
	gotoxy(32, 12);
	cout << "Enter the value of c: ";
	gotoxy(55, 12);
	cin >> c;

	int dscrmnt, ac, sec;

	ac = 4 * (a * c);
	sec = b * b;
	dscrmnt = sec - ac;
	gotoxy(32, 14);
	cout << "The discriminant is " << dscrmnt;
}
void sdpq(int num1, int num2)
{
	gotoxy(25, 8);
	cout << "SUM, DIFFERENCE, PRODUCT, QUOTIENT";
	int sum, diff, pro, quo;

	sum = num1 + num2;
	diff = num1 - num2;
	pro = num1 * num2;
	quo = num1 / num2;
	gotoxy(32, 13);
	cout << "The sum is " << sum << ".";
	gotoxy(32, 14);
	cout << "The difference is " << diff << ".";
	gotoxy(32, 15);
	cout << "The product is " << pro << ".";
	gotoxy(32, 16);
	cout << "The quotient is " << quo << ".";
}
void helwo()
{
	cout << "HELLO WORLD";
}

//MAINMENU OF SEQUENCE
void sqcm()
{
	char choice;
	do {
		system("CLS");
		border();
		gotoxy(52, 4);
		WriteInColor(80, "-------------------");
		gotoxy(54, 5);
		WriteInColor(70, " SEQUENCE MENU "); WriteInColor(07, "");
		gotoxy(52, 6);
		WriteInColor(80, "-------------------");
		gotoxy(45, 9);
		WriteInColor(80, "A."); WriteInColor(03, " - HELLO WORLD"); WriteInColor(01, "");
		gotoxy(45, 10);
		WriteInColor(80, "B."); WriteInColor(03, " - ARITMETIC OPERATIONS"); WriteInColor(01, "");
		gotoxy(45, 11);
		WriteInColor(80, "C."); WriteInColor(03, " - ROOTS OF QUADRATIC EQUATION"); WriteInColor(01, "");
		gotoxy(45, 12);
		WriteInColor(80, "D."); WriteInColor(03, " - AREA AND PERIMETER"); WriteInColor(01, "");
		gotoxy(45, 13);
		WriteInColor(80, "E."); WriteInColor(03, " - SWAPPED VALUES"); WriteInColor(01, "");
		gotoxy(45, 14);
		WriteInColor(80, "F."); WriteInColor(03, " - AVERAGE"); WriteInColor(01, "");
		gotoxy(45, 15);
		WriteInColor(80, "G."); WriteInColor(03, " - AREA AND CIRCUMFERENCE"); WriteInColor(01, "");
		gotoxy(45, 16);
		WriteInColor(80, "H."); WriteInColor(03, " - CELSIUS AND FAHRENHEIT"); WriteInColor(01, "");
		gotoxy(45, 17);
		WriteInColor(80, "I."); WriteInColor(03, " - GROSS PAY AND NET PAY"); WriteInColor(01, "");
		gotoxy(45, 18);
		WriteInColor(80, "J."); WriteInColor(03, " - SQUARE AND CUBE"); WriteInColor(01, "");
		gotoxy(45, 19);
		WriteInColor(80, "K."); WriteInColor(03, " - EXIT"); WriteInColor(01, "");
		gotoxy(45, 21);
		WriteInColor(80, "ENTER YOU CHOICE. "); WriteInColor(01, "");
		gotoxy(64, 21);
		cin >> choice;

		switch (choice)
		{
		case 'A': 
		case 'a':
			system("CLS"); //funtion without argument and does not return a value
			gotoxy(35, 8);
			helwo();
			_getch();
			break;

		case 'B': 
		case 'b':
			system("CLS"); //function with arguments and does not return a value
			int num1, num2;
			gotoxy(32, 10);
			cout << "Enter first number.";
			gotoxy(53, 10);
			cin >> num1;
			gotoxy(32, 11);
			cout << "Enter second number.";
			gotoxy(53, 11);
			cin >> num2;
			sdpq(num1, num2);
			_getch();

			break;

		case 'C': 
		case 'c':
			system("CLS");  //funtion without argument and does not return a value
			roots();
			_getch();
			break;

		case 'D': 
		case 'd':
			system("CLS"); //funtion with arguments and returns a value
			int l, w;
			gotoxy(32, 10);
			cout << "Input the length: ";
			gotoxy(51, 10);
			cin >> l;
			gotoxy(32, 11);
			cout << "Input the width: ";
			gotoxy(51, 11);
			cin >> w;
			ap(l, w);
			_getch();
			break;

		case 'E': 
		case 'e':
			system("CLS"); //funtion with arguments and does not return a value
			char var1, var2;
			gotoxy(32, 10);
			cout << "Input variable 1: ";
			gotoxy(51, 10);
			cin >> var1;
			gotoxy(32, 11);
			cout << "Input variable 2: ";
			gotoxy(51, 11);
			cin >> var2;
			swap(var1, var2);
			_getch();
			break;

		case 'F': 
		case 'f':
			system("CLS"); //funtion without argument and returns a value
			float average;
			average = ave();
			gotoxy(32, 17);
			cout << "The average is " << average << endl;
			_getch();
			break;

		case 'G': 
		case 'g':
			system("CLS"); //funtion without argument and does not return a value
			arcr();
			_getch();
			break;

		case 'H': 
		case 'h':
			system("CLS");  //funtion with arguments and returns a value
			float farenheit, celsius;
			gotoxy(32, 10);
			cout << "Input the Celsius. ";
			gotoxy(53, 10);
			cin >> celsius;
			farenheit = temp(celsius);
			gotoxy(32, 11);
			cout << "Farenheit: " << setprecision(2) << farenheit << endl;
			_getch();
			break;

		case 'I': 
		case 'i':
			system("CLS"); //funtion without argument and does not return a value
			gpnp();
			_getch();
			break;

		case 'J':
		case 'j':
			system("CLS");  //funtion with arguments and does not return a value
			int numbe1;
			gotoxy(32, 10);
			cout << "Input a number: ";
			gotoxy(49, 10);
			cin >> numbe1;
			sqac(numbe1);
			_getch();
			break;

		case 'K':
		case 'k':
			//exit
			break;
		}
	} while (choice < 'K' && choice < 'k');
}
