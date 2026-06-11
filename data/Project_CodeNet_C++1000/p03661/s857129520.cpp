#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	long long n,sum=0,min,bmin;
	scanf("%d",&n);
	long long *a=new long long [n];
	long long *b=new long long [n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		b[i]=sum;
	}
	min=abs(2*b[0]-sum);
	for(int i=1;i<n-1;i++)
	{
		bmin=abs(2*b[i]-sum);
		if(bmin<min)
		{
			min=bmin;
		}
	 } 
	 cout<<min;
	 return 0;
}