#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");

	int array[] = {1,5,7,8,3,3,4,6,8,2,31,1};
	int size = sizeof(array)/sizeof(array[0]);

	for(int ctr1=0; ctr1<size; ctr1++)
	{
		cout<<array[ctr1]<<" ";
	}
	cout<<endl;

	//save searched value
	int indexes[50];
	int occurences=0;

	//find
	int number=0;

	cout<<"Enter the number to be searched: ";
	cin>>number;

	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"Please enter a valid number: ";
		cin>>number;
	}

	for(int ctr=0; ctr<size; ctr++)
	{
		if(array[ctr]==number)
		{
			indexes[occurences]=ctr;
			occurences++;
		}
	}

	cout<<endl;
	if(occurences == 0)
	{
		cout<<"AWTS T_T The number is not in the list."<<endl;
	}
	else
	{
		cout<<"Number of occurence/s: "<<occurences<<endl;
		cout<<"The number is found in place/s: ";
		for(int ctr2 = 0; ctr2<occurences; ctr2++)
		{
			cout<<indexes[ctr2]+1<<" ";
		}
		cout<<endl;
		cout<<"The number is found in index: ";
		for(int ctr3 = 0; ctr3<occurences; ctr3++)
		{
			cout<<indexes[ctr3]<<" ";
		}

	}

    cout<<endl;
	cin.get();
}
