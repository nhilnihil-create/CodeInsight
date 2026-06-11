#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char a[100010],b[100010];
int cc,flag=1;

void jud()
{
	for(int i=0;i<cc-1;i++)
	{
		if(a[i]!=b[cc-i-2])
		{
			flag=0;
			return ;
		}
	}
}

int main( )
{
	while(~scanf("%c",&a[cc]))
	{
		cc++;
	}
	for(int i=0;i<cc;i++)
	{
		if(a[i]=='p')b[i]='q';
		if(a[i]=='q')b[i]='p';
		if(a[i]=='b')b[i]='d';
		if(a[i]=='d')b[i]='b';
	}
	jud();
	if(flag==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}