#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q,k,cnt=0;
int head[100005],father[100005][25],depth[100005],lg[100005],pre[100005];

struct edge
{
	int next;
	int to;
	int dis;
}e[200005];

inline void add_edge(int u,int v,int w)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dfs(int now,int fath)
{
	depth[now]=depth[fath]+1;
	father[now][0]=fath;
	
	for (int i=1;i<=lg[depth[now]];i++)  father[now][i]=father[father[now][i-1]][i-1];
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)  dfs(e[i].to,now);
	}
}

inline void dfs2(int now,int fath,int w)
{
	pre[now]=pre[fath]+w;
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)  dfs2(e[i].to,now,e[i].dis);
	}
}

int LCA(int u,int v)
{
	if (depth[u]<depth[v])  swap(u,v);
	while (depth[u]>depth[v])  u=father[u][lg[depth[u]-depth[v]]-1];
	if (u==v)  return u;
	
	for (int k=lg[depth[u]];k>=0;k--)
	{
		if (father[u][k]!=father[v][k])
		{
			u=father[u][k];
			v=father[v][k];
		}
	}
	return father[u][0];
}

inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	
	while (ch<'0'||ch>'9')
	{
		if (ch=='-')  w=-w;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		s=(s<<1)+(s<<3)+(ch-'0');
		ch=getchar();
	}
	return s*w;
}

int query(int u,int v)
{
	int p=LCA(u,v);
	return (pre[u]-pre[p])+(pre[v]-pre[p]);
}

signed main()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for (int i=1;i<=n;i++)  lg[i]=lg[i-1]+((1<<lg[i-1])==i);
	
	cin>>q>>k;
	dfs(1,0);
	dfs2(1,0,0);
	
	for (int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<query(u,k)+query(v,k)<<endl;
	}
	return 0;
}