#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");

	int array[]={0,123,-1,1231,11,23,9,10,1};
	int temp=0;

	int index_of_lowest=0;

	int size = sizeof(array)/sizeof(array[0]);

	for(int ctr0=0;ctr0<size;ctr0++)
		{
			cout<<array[ctr0]<<" ";
		}
    cout<<endl<<endl;
	for(int ctr=0; ctr<size; ctr++)
	{
		//set the lowest index to first element in the array
		index_of_lowest = ctr;

		for(int ctr2=ctr+1; ctr2<size; ctr2++)
		{
			if(array[ctr2]<array[index_of_lowest])
			{
				index_of_lowest = ctr2;
			}
		}

		temp = array[ctr];
		array[ctr] = array[index_of_lowest];
		array[index_of_lowest] = temp;

		for(int ctr4=0;ctr4<size;ctr4++)
		{
			cout<<array[ctr4]<<" ";
		}
		cout<<endl;

	}
	cout<<endl;

	cout<<"\n The sorted elements in the array are: ";
	for(int ctr3=0;ctr3<size;ctr3++)
	{
		cout<<array[ctr3]<<" ";
	}

	cin.get();
}
