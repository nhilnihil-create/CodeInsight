#include<iostream>
#include<cstdio>
#include<cstring>
#define E 100010
using namespace std;

char s[E],ss[E];

int main()
{
	scanf("%s",s);
	
	int len=strlen(s);
	for(int i=0;i<len;i++)ss[i]=s[len-i-1];
	for(int i=0;i<len;i++)
	{
		if(ss[i]=='b')
		{
			ss[i]='d';
			continue;
		}
		if(ss[i]=='d')
		{
			ss[i]='b';
			continue;
		}
		if(ss[i]=='p')
		{
			ss[i]='q';
			continue;
		}
		if(ss[i]=='q')
		{
			ss[i]='p';
			continue;
		}
	}
	
	for(int i=0;i<len;i++)
	{
		if(s[i]!=ss[i])
		{
			cout<<"No"<<endl;
			return 0;
		}
		else continue;
	}
	cout<<"Yes"<<endl;
	
	return 0;
}