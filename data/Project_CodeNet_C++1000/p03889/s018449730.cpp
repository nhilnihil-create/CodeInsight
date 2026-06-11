#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char a[100000],b[100000];
int main()
{
	int n,m,s=0;
	cin>>a;
	n=strlen(a);
	m=n;
	for(int i=0;i<n;i++)
	{
		b[i]=a[m-1];
		m--;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]=='b')
		{
			b[i]='d';
		}
		else if(b[i]=='d')
		{
			b[i]='b';
		}
		else if(b[i]=='p')
		{
			b[i]='q';
		}
		else if(b[i]=='q')
		{
			b[i]='p';
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[i])
		{
			s++;
		}
	}
	if(s==n)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}