#include <bits/stdc++.h>
using namespace std;
int n,a,b,cnt1,cnt2,dist1[100001],dist2[100001];
vector<int> g[100001];
void dfs1(int v,int p)
{
	for (int i=0;i<g[v].size();++i)
		if (g[v][i]!=p)
		{
			dist1[g[v][i]]=dist1[v]+1;
			dfs1(g[v][i],v);
		}
}
void dfs2(int v,int p)
{
	for (int i=0;i<g[v].size();++i)
		if (g[v][i]!=p)
		{
			dist2[g[v][i]]=dist2[v]+1;
			dfs2(g[v][i],v);
		}
}
int main()
{
	cin>>n;
	for (int i=0;i<n-1;++i)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1,1);
	dfs2(n,n);
	for (int i=1;i<=n;++i)
		if (dist1[i]<=dist2[i]) ++cnt1;
		else ++cnt2;
	if (cnt1>cnt2) cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}