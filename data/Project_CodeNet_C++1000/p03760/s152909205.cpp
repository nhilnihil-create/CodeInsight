#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	if(a.size()==b.size())
	{
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i]<<b[i];
		}
		
	}
	else
	{
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i];
			if(i<b.size())
			{
				cout<<b[i];
			}
		}
	}
}
