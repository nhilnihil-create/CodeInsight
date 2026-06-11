#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
int n,k,m,h[N],cnt,ans=1e9,sm;
struct qwe
{
	int ne,no,to;
}e[N];
int read()
{
	int r=0,f=1;
	char p=getchar();
	while(p>'9'||p<'0')
	{
		if(p=='-')
			f=-1;
		p=getchar();
	}
	while(p>='0'&&p<='9')
	{
		r=r*10+p-48;
		p=getchar();
	}
	return r*f;
}
void add(int u,int v)
{
	cnt++;
	e[cnt].ne=h[u];
	e[cnt].no=u;
	e[cnt].to=v;
	h[u]=cnt;
}
void dfs(int u,int fa,int de)
{
	if(de>m)
		sm++;
	for(int i=h[u];i;i=e[i].ne)
		if(e[i].to!=fa)
			dfs(e[i].to,u,de+1);
}
int main()
{
	n=read(),k=read(),m=k/2;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	if(k&1)
	{
		for(int i=1;i<=cnt;i+=2)
		{
			sm=0;
			dfs(e[i].no,e[i].to,0);
			dfs(e[i].to,e[i].no,0);
			ans=min(ans,sm);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			sm=0;
			dfs(i,0,0);
			ans=min(ans,sm);
		}
	}
	printf("%d\n",ans);
	return 0;
}