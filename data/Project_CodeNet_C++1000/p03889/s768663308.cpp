#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,str,flag=1;
	char a[101000],b[101000];
	cin>>a;
	str=strlen(a);
	for(i=0;i<str;i++)
	{
		b[str-i-1]=a[i];
	}
	for(i=0;i<str;i++)
	{
		if(b[i]=='b')b[i]='d';
		else if(b[i]=='d')b[i]='b';
		else if(b[i]=='p')b[i]='q';
		else if(b[i]=='q')b[i]='p';
	}
	for(i=0;i<str;i++)
	{
		if(a[i]!=b[i])
		{
			cout<<"No"<<endl;
			flag=0;
			break;
		}
	}
	if(flag==1)cout<<"Yes"<<endl;
} 