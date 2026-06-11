#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100010
int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],c;
void AddEdge(int u,int v)
{
	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;
}
int vis[MAXN],st[MAXN],col[MAXN],dis[MAXN],cnt,sd[MAXN];
void BFS(int s,int d,int C)
{
	if(dis[s]>=d) return;
	dis[s]=d,vis[s]=cnt;
	if(col[s]==0) col[s]=C;
	int l=0,r=0;
	st[r]=s;
	sd[r++]=0;
	while(l<r)
	{
		int u=st[l];
		if(sd[l++]==d) continue;
		int nd=d-sd[l-1]-1;
		for(int i=Adj[u];i;i=nxt[i])
			if(vis[V[i]]!=cnt)
			{
				int v=V[i];
				vis[v]=cnt;
				if(dis[v]>=nd) continue;
				if(col[v]==0) col[v]=C;
				dis[v]=nd;
				st[r]=v;
				sd[r++]=sd[l-1]+1;
			}
	}
}
int n,m,s[MAXN],d[MAXN],C[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	memset(dis,-1,sizeof dis);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	scanf("%d",&cnt);
	for(int i=1;i<=cnt;i++)
		scanf("%d%d%d",&s[i],&d[i],&C[i]);
	while(cnt)
	{
		BFS(s[cnt],d[cnt],C[cnt]);
		cnt--;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",col[i]);
}