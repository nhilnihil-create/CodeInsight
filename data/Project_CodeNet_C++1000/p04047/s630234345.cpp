#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[2*n];
	for(int i=0;i<2*n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<2*n;i++)
	{
		for(int j=i;j<2*n;j++)
		{
		if(arr[i]>arr[j])
		{
			int temp;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
		}
		
	}

	int sum=0;
	for(int i=0;i<2*n;i++)
	{
		if(i%2==0)
		{
		sum=sum+arr[i];
		}
	}
	cout<<sum;
	
	return 0;
}