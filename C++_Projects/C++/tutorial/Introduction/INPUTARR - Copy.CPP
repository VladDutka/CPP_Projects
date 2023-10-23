#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");

	int array[10]={0};

	int size = sizeof(array)/sizeof(array[0]);

	for(int ctr=0; ctr<size; ctr++)
	{
		cout<<"Enter a value for index: ["<<ctr<<"]: ";
		cin>>array[ctr];
	}

	cout<<"\n The elements in the the array are: ";
	for(int ctr2=0; ctr2<size; ctr2++)
	{
		cout<<array[ctr2]<<" ";
	}

	cin.get();
}
