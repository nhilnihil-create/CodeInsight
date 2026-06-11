#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,a,b,c,d;
	cin>>n>>a>>b;
	c=b+(a*(n-1));
	d=a+(b*(n-1));
	d=d-c+1;
	
	
	if(d<=0 || a>b)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<d<<endl;
	}
}