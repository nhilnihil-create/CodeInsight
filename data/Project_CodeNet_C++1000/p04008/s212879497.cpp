#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

inline int read()
{
	int ret=0; char ch=getchar();
	while (!(ch>='0' && ch<='9')) ch=getchar();
	while (ch>='0' && ch<='9') ret=ret*10+(ch-'0'),ch=getchar();
	return ret;
}

const int maxn=100005;

struct edges{
	int next,to;
} ed[maxn<<2];
int head[maxn],ip;
void add(int u,int v)
{
	ed[++ip].next=head[u];
	ed[ip].to=v;
	head[u]=ip;
}

int n,k,ans;
int a[maxn],dis[maxn];

void dfs(int u,int father)
{
	dis[u]=1;
	int v;
	for (int i=head[u]; i; i=ed[i].next)
	{
		v=ed[i].to;
		if (v!=father)
		{
			dfs(v,u);
			dis[u]=max(dis[u],dis[v]+1);
		}
	}
	if (dis[u]>=k && a[u]>1)
	{
		ans++;
		dis[u]=0;
	}
}

int main()
{
	n=read(); k=read();
	for (int i=1; i<=n; i++)
		a[i]=read();
	if (a[1]!=1)
	{
		a[1]=1;
		ans++;
	}
	for (int i=2; i<=n; i++)
		add(a[i],i),add(i,a[i]);
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}