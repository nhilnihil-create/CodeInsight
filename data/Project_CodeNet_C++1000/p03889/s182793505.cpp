#include<bits/stdc++.h>
using namespace std;
string a,b;
int t;
char c[1000000];
int main()
{
	cin>>a;
	int l=a.size();
	b=a;
	for(int i=l-1;i>=0;i--)
		c[l-i-1]=a[i];
	for(int i=0;i<=l-1;i++)
	{
		if(c[i]=='b')
			c[i]='d';
		else if(c[i]=='d')
			c[i]='b';
		else if(c[i]=='p')
			c[i]='q';
		else if(c[i]=='q')
			c[i]='p';
	}
	for(int i=0;i<l;i++)
	{
		if(c[i]!=b[i])
			t=1;
	}
	if(t==0)
		cout<<"Yes"<<'\n';
	else
		cout<<"No"<<'\n';
	return 0;
}