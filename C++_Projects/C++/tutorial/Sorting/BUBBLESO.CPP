#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");

	int array[10]={0,-23,5,43,1,5,7,9,10,1};
	int temp=0;

	int size = sizeof(array)/sizeof(array[0]);

	for(int ctr=0; ctr<size; ctr++)
	{
		for(int ctr2=ctr+1; ctr2<size; ctr2++)
		{
			if(array[ctr]>array[ctr2])
			{
				temp=array[ctr];
				array[ctr]=array[ctr2];
				array[ctr2]=temp;
			}
		}

        for(int ctr3=0;ctr3<size;ctr3++)
        {
            cout<<array[ctr3]<<" ";
        }
        cout<<endl;
	}

	cout<<"\n The sorted elements in the array are: ";
	for(int ctr4=0;ctr4<size;ctr4++)
	{
		cout<<array[ctr4]<<" ";
	}

	cin.get();
}
