#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	system("cls");
	//list
	int array[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,71,99};
	int size = sizeof(array)/sizeof(array[0]);

	//number to be find
	int number=0;
	int place=-1;

	//right, left, and middle variables;
	int left = 0;
	int right = size-1;
	int mid = 0;

	for(int ctr0 = 0; ctr0<size; ctr0++)
    {
        cout<<array[ctr0]<<" ";
    }
    cout<<endl;

	cout<<"Enter a number to be searched: ";
	cin>>number;

	while(right>=left)
	{
		mid = (left + right)/2;

		if(number == array[mid])
		{
			place = mid;
			break;
		}
		else if(number > array[mid])
		{
			left = mid+1;
		}
		else
		{
			right = mid-1;
		}
	}

	cout<<endl;
	if(place == -1)
	{
		cout<<"Wala lods ahahaha"<<endl;
	}
	else
	{
		cout<<"The number is element number: ["<<place+1<<"] or in index: ["<<place<<"]"<<endl;
	}

	cin.get();
}
