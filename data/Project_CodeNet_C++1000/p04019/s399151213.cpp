#include <bits/stdc++.h>
using namespace std;
int  main()
{
	string s;
	cin>>s;
	int i,n,a=0,b=0,c=0,d=0;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]=='N')
		{
			a=1;
		}
		else if(s[i]=='W')
		{
			b=1;
		}
		else if(s[i]=='E')
		{
			c=1;
		}
		else if(s[i]=='S')
		{
			d=1;
		}
	}
	if((a!=d) || (c!=b))
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	
}