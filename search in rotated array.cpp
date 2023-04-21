#include<iostream>
using namespace std;
int pivotelement(int arr[],int n){
	
	int s=0;
	int e=n-1;
	int mid=s+(e-s)/2;
	while(s<e)
	{
		if(arr[mid]>=arr[0])
		{
			s=mid+1;
		}
		else{
			e=mid;
		}
		mid=s+(e-s)/2;
	}
	return s;
}

int binnarySearch(int arr[],int s,int e,int key)
{
	int start = s;
	int end = e;
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
int searchinrotatedarray(int arr[],int key,int n)
{
	int pivot=pivotelement(arr, n);
	if(key>=arr[pivot] && key<=arr[n-1])
	{
		return binnarySearch( arr, pivot,n-1,key);
	}
	else{
		return binnarySearch( arr,0,pivot-1, key);
	}

}
int main()
{
	
	int arr[5]={7,9,1,2,3};
	cout<<"index of element is:-"<< searchinrotatedarray(arr,3,5);
	return 0;
}
