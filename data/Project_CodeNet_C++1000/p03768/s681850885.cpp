#include<bits/stdc++.h>
#define MAX 100000
#define INF 1000
using namespace std;
int n,m,Q,v[MAX+5],d[MAX+5],c[MAX+5],rec[MAX+5];
int vis[MAX+5],way[MAX+5],MinDis[MAX+5];
vector<int>edge[MAX+5];
void run()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) rec[i]=-1,MinDis[i]=-1;
	for(int i=1; i<=m; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	scanf("%d",&Q);
	for(int i=1; i<=Q; i++)
    scanf("%d%d%d",&v[i],&d[i],&c[i]);
}
void dfs(int from,int dis,int col)
{
	if(MinDis[from]>=dis) return; 
	else MinDis[from]=dis;
	vis[from]=1;
	way[from]=1;
	for(int i=0; i<edge[from].size(); i++)
	{
		int to=edge[from][i];
		if(way[to]) continue;
		if(dis>=1) 
		{
		rec[to]=(!vis[to])?col:rec[to];
		dfs(to,dis-1,col);
	    }
	}
	way[from]=0;
}
void solve()
{
	for(int i=Q; i>=1; i--)
	{
	if(!vis[v[i]]) rec[v[i]]=c[i];
	dfs(v[i],d[i],c[i]);
    }
}
void lprint()
{
	for(int i=1; i<=n; i++)
	{
		int check=(rec[i]==-1)?0:rec[i];
		printf("%d\n",check);
	}
}
int main()
{
	run();
	solve();
	lprint();
	return 0;
}