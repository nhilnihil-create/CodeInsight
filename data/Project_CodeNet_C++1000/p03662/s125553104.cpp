#include<iostream>
#include<cstdio>
using namespace std;
int siz[101000],fa[101000];
int h[101000],nxt[201000],K=0,to[201000];
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
void dfs(int x,int f)
{
	fa[x]=f;siz[x]=1;
	for(int i=h[x];i;i=nxt[i])
	{
		if(to[i]==f)continue;
		dfs(to[i],x);siz[x]+=siz[to[i]];
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		ins(a,b);ins(b,a);
	}
	dfs(1,0);int tot=0;
	for(int i=fa[n];i!=1;i=fa[i])tot++;
	int k=n;
	for(int i=1;i<=tot/2;i++)k=fa[k];
	int ls1=n-siz[k]-(tot-tot/2),ls2=siz[k]-tot/2;
	if(tot&1)
	{
		if(ls2<=ls1)puts("Fennec");
		else puts("Snuke");
	}
	else
	{
		if(ls1<=ls2)puts("Snuke");
		else puts("Fennec");
	}
	return 0;
}