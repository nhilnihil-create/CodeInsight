#include<bits/stdc++.h>
using namespace std;
int n,m;
int q;
int v[100005],d[100005],c[100005];
vector<int> g[100005];
int colour[100005];
int mindis[100005];
inline void dfs(int x,int dleft,int c)
{
	if(dleft<=mindis[x])
	{
		return;
	}
	mindis[x]=dleft;
	if(colour[x]==0)
	{
		colour[x]=c;
	}
	for(int i=0;i<g[x].size();i++)
	{
		dfs(g[x][i],dleft-1,c);
	}
}
int main()
{
	cin>>n>>m;
	memset(mindis,-1,sizeof(mindis));
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>v[i]>>d[i]>>c[i];
	}
	for(int i=q-1;i>=0;i--)
	{
		dfs(v[i]-1,d[i],c[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<colour[i]<<endl;
	}
	return 0;
}