#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
char ch[2][2]={{'R','B'},{'G','Y'}};	
int n,m,d;
char calc (int x,int y)
{
	int a=(x+y),b=(x-y);
	a=a+1000;b=b+1000;
	a/=d;b/=d;
	return ch[a&1][b&1];
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=m;i++)
		printf("%c",calc(u,i));
		printf("\n");
	}
	return 0;
}