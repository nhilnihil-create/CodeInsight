#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	long long n,x,sum=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(a[1]>=x) 
	{
		sum+=a[1]-x;
		a[1]=x;
	}
	for(int i=1;i<n;i++)
	{
		int t=a[i]+a[i+1]-x;
		if(t<=0) continue;
		if(a[i]>=x)
		{
			sum+=t;
			a[i+1]=0;
			 
		 }
		 else
		 {
		 	sum+=t;
			a[i+1]=x-a[i];
		 } 
 	}
 	cout<<sum<<endl;
 } 