#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int a,b,c,x,y,z,i,k=0;
	cin>>a>>b>>c;
	if(a%2!=0 || b%2!=0 || c%2!=0)
	{
		cout<<k<<endl;
		return 0;
	}
	for(i=0;(a!=b || b!=c);i++)
	{
	x=(b+c)/2;
	y=(a+c)/2;
	z=(a+b)/2;
	a=x;
	b=y;
	c=z;
	k++;
	if(a%2!=0 || b%2!=0 || c%2!=0)
	{
		cout<<k<<endl;
		return 0;
	}
	
	}
	cout<<-1<<endl;
}