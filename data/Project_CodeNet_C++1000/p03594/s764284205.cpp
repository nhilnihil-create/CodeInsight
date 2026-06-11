#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;	char ch=getchar();
	while(ch<'0'||ch>'9')	{if(ch=='-')	f=-1;	ch=getchar();}
	while(ch>='0'&&ch<='9')	{x=(x<<3)+(x<<1)+(ch^48);	ch=getchar();}
	return x*f;
}
int n,m,t;
char s[4]={'R','Y','G','B'};
int main()
{
	n=read();	m=read();	t=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int x=(i+j+m)/t;	int y=(i-j+m)/t;
			printf("%c",s[((x&1)<<1)|(y&1)]);
		}
		printf("\n");
	}
	return 0;
}