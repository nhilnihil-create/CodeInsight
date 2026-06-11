#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100005];
int dist1[100005];
int dist2[100005];
void dfs1(int v,int p)
{
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]!=p)
		{
			dist1[g[v][i]]=dist1[v]+1;
			dfs1(g[v][i],v);
		}
	}
}
void dfs2(int v,int p)
{
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]!=p)
		{
			dist2[g[v][i]]=dist2[v]+1;
			dfs2(g[v][i],v);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1,1);
	dfs2(n,n);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<dist1[i]<<" "<<dist2[i]<<endl;
		if(dist1[i]<=dist2[i])
		{
			cnt1++;
		}
		else
		{
			cnt2++;
		}
	}
	if(cnt1>cnt2)
	{
		cout<<"Fennec";
	}
	else
	{
		cout<<"Snuke";
	}
	return 0;
}