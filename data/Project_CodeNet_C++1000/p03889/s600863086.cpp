#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
char a[1000001];

int main()
{
	cin>>a;
	int na=strlen(a);
	if(na%2!=0)
	{
		cout<<"No";
		return 0;
	}
	for(int i=0;i<na/2;++i)
	{
		if(a[i]=='b') a[i]='d';
		else if(a[i]=='d') a[i]='b';
		else if(a[i]=='p') a[i]='q';
		else if(a[i]=='q') a[i]='p';
	}
	int bz1=0,bz2=na-1;
	while(bz1<=bz2)
	{
		if(a[bz1]!=a[bz2])
		{
			cout<<"No";
			return 0;
		}
		bz1++;
		bz2--;
	}
	cout<<"Yes";
	return 0;
}