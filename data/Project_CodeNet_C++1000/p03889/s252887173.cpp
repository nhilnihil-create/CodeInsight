#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int len;
int main()
{
	string s,x;
	cin>>s;
	len=s.length();
	x=s;
	for(int i=0;i<len;i++)
		x[i]=s[len-i-1];
	for(int i=0;i<len;i++)
	{
		if(x[i]=='b')
		{
			x[i]='d';
			continue;
		}
		if(x[i]=='d')
		{
			x[i]='b';
			continue;
		}
		if(x[i]=='p')
		{
			x[i]='q';
			continue;
		}
		if(x[i]=='q')
		{
			x[i]='p';
			continue;
		}
	}
	bool flag=true;
	for(int i=0;i<len;i++)
		if(x[i]!=s[i])
			flag=false;
	if(flag==true)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}