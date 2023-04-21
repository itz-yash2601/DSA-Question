#include<iostream>
using namespace std;
bool possible(int arr[],int n, int m,int mid){
	int student=1;
	int pagecount=0;
	for(int i=0;i<n;i++){
		if(pagecount+arr[i]<=mid){
			pagecount += arr[i];
		}
		else{
			student++;
			if( student>m||arr[i]>mid)
			{
				return false;
			}
			pagecount=arr[i];
			
		}
	}
	return true;
}
int allocation(int arr[],int n,int m)
{
	int s=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	int e=sum;
	int mid=s+(e-s)/2;
	int ans=-1;
	while(s<=e)
	{
		if(possible(arr,n,m,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}
int main()
{
	int arr[4]={12,34,67,90};
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<"Minimum number of allocation :-"<<allocation(arr,n,2);
	return 0;
}
