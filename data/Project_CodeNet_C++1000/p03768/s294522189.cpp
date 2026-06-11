#include"bits/stdc++.h"
#include"vector"
using namespace std;
int n,m;
int a[100005],b[100005],c[100005];
int dist[100005];
int color[100005];
vector<int> v[100005];
void dfs(int u,int dis,int co)
{
	if(dis<=dist[u]||dis<0)
	{
		return ;
	}
	dist[u]=dis;
	if(color[u]==0) color[u]=co;
	for(int i=0;i<v[u].size();i++)
	{
		dfs(v[u][i],dis-1,co);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=q;i>=1;i--)
	{
		dfs(a[i],b[i]+1,c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<color[i]<<endl;
	}
}