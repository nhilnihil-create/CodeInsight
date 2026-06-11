#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 505
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,pos=1,a[MAX*MAX],p[MAX],x[MAX];
bool vis[MAX];
bool cmp(int a,int b){return x[a]<x[b];}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)x[i]=read(),a[x[i]]=i,p[i]=i;
	sort(&p[1],&p[n+1],cmp);
	for(int i=1;i<=n;++i)
	{
		int v=p[i];
		for(int j=1;j<v;++j)
		{
			while(a[pos])++pos;
			a[pos]=v;
		}
		if(pos>x[v]){puts("No");return 0;}
	}
	for(int i=1;i<=n;++i)
	{
		int v=p[i];
		for(int j=1;j<=n-v;++j)
		{
			while(a[pos])++pos;
			if(pos<x[v]){puts("No");return 0;}
			a[pos]=v;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;++i)printf("%d ",a[i]);puts("");
	return 0;
}
