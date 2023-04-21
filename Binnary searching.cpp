#include<iostream>
using namespace std;
int binnarySearch(int arr[],int size,int key)
{
	int start = 0;
	int end = size-1;
	int mid = (start + end)/2;
	
	while(start<=end )
	{
		if (arr[mid]==key){
			return mid;
		}
		if(key>arr[mid])
		{
			start = mid+1;
		}
		else{
			end= mid-1;
		}
		mid = (start+end)/2;//start+ ((end-start)/2 )
	}
	return -1;
		
}
int main()
{
	
	int even[4]={1,2,3,4}; 
	int index = binnarySearch(even,4,2);
	cout<<"Index of key"<<index<<endl;
	return 0; 
}
