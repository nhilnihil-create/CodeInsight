#include<bits/stdc++.h>
using namespace std;
char a[10000100],b[10000100];
int len;

void fz()
{
	char cc[10000100];
	for(int i=len-1,j=0;i>=0;i--,j++)
	{
		cc[j]=a[i];
	}
	strcpy(a,cc);
}

int main()
{
	cin>>a;
	strcpy(b,a);
	len=strlen(a);
	fz();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='b') a[i]='d';
		else if(a[i]=='d') a[i]='b';
		else if(a[i]=='q') a[i]='p';
		else if(a[i]=='p') a[i]='q';
	}
	if(strcmp(a,b)==0)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
} 