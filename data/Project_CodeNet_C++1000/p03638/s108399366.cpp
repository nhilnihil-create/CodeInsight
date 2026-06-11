#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	int a[n];
	int arr[h][w];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k=0;
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<a[i];j++)
		{
			int r = k/w;
			int c = k%w;
			if(r%2!=0)
				c=w-c-1;
			arr[r][c]=(i+1);
			//cout<<r<<" "<<c<<"\n";
			k++;
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}



}