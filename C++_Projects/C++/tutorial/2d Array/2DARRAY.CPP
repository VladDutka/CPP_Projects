#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");

	//rows and cols
	int rows = 2;
	int cols = 3;

	//2d array   rows  cols
	int  array   [2]  [3];

	for(int row=0; row<rows; row++)
	{
		for(int col = 0; col<cols; col++)
		{
		    cout<<"Enter a value for row ["<<row<<"] and column ["<<col<<"]: ";
			//array[ctr][ctr2] = (ctr+1)*(ctr2+1);
			cin>>array[row][col];
		}

	}

	/*
        1 2 3  4 5
        2 4 6  8 10
        3 6 9 12 15
	*/

	for(int ctr3=0; ctr3<rows; ctr3++)
	{
		for(int ctr4 = 0; ctr4<cols; ctr4++)
		{
			cout<<array[ctr3][ctr4]<<"\t";
		}
		cout<<endl;
	}


	cin.get();
}
