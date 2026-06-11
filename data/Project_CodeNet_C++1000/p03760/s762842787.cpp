#include <bits/stdc++.h>
using namespace std;
int main()
{
	string o,e;
	cin>>o>>e;
	int i,a,b;
	a=o.size();
	b=e.size();
	if(a>=b)
	{
	for(i=0;i<a;i++)
	{
		cout<<o[i];
		if(i<b)
		{
		cout<<e[i];
		}
	}
	}
	if(b>a)
	{
	for(i=0;i<b;i++)
	{
		
		if(i<a)
		{
		cout<<o[i];
		
		}
		cout<<e[i];
	}
	}
}