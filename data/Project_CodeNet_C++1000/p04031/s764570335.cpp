#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s=0,x;
	cin>>n;
	int shu[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>shu[i];
		s+=shu[i];
	}
	x=s/n;
	int a=0,b=0,c=0;
	for(int i=1;i<=n;i++)
	{
		a+=(shu[i]-x+1)*(shu[i]-x+1);
		b+=(shu[i]-x)*(shu[i]-x);
		c+=(shu[i]-x-1)*(shu[i]-x-1);
	}
	cout<<min(min(a,b),c);
}