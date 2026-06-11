#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
vector<int>g[4005];
int n,k,q[4005],t,dist[4005],ans=2005;
void bfs()
{
	for(int k=0;k<t;k++)
	{
		int v=q[k];
		for(int l=0;l<g[v].size();l++)
		{
			int u=g[v][l];
			int w=dist[v]+2;
			if(dist[u]<=w)
				continue;
			dist[u]=w;
			q[t++]=u;
		}
	}
	return;
}
int sv(int v)
{
	for(int i=0;i<n;i++)
		dist[i]=inf;
	dist[v]=0;
	t=0;
	q[t++]=v;
	bfs();
	int res=0;
	for(int i=0;i<n;i++)
		if(dist[i]>k)
			res++;
	return res;
}
int se(int v,int u)
{
	for(int i=0;i<n;i++)
		dist[i]=inf;
	dist[v]=dist[u]=1;
	t=0;
	q[t++]=v;
	q[t++]=u;
	bfs();
	int res=0;
	for(int i=0;i<n;i++)
		if(dist[i]>k)
			res++;
	return res;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int v,u;
		cin>>v>>u;
		v--;
		u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int v=0;v<n;v++)
		ans=min(sv(v),ans);
	for(int v=0;v<n;v++)
		for(int i=0;i<g[v].size();i++)
		{
			int u=g[v][i];
			if(u>v)
				ans=min(ans,se(v,u));
		}
	cout<<ans;
	return 0;
}