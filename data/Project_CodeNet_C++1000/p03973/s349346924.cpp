#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int arr[n],count=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	count+=arr[0]-1;
	long long int check=1;
for(int i=1;i<n;i++)
{
	if(arr[i]==check+1)
		check++;
	else
		count+=(arr[i]-1)/(check+1);
}
	cout<<count<<endl;


	return 0;
}