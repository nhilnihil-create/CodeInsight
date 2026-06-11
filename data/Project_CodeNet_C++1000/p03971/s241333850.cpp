#include <bits/stdc++.h>
using namespace std;
int main()
{
long int n,a,b,i,d=0,x=0;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='c')
		{
			cout<<"No"<<endl;
		}
		
		if(s[i]=='a')
		{
			if(d<a+b)
			{
				cout<<"Yes"<<endl;
				d++;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		
		if(s[i]=='b')
		{
			x++;
			if(d<a+b && x<=b)
			{
				cout<<"Yes"<<endl;
				d++;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		
		
	}
}