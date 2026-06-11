#include<bits/stdc++.h>
using namespace std;
int n,k,sz[2222],dp[2222][2222],ndp[2222][2222];
vector<int>adj[2222];
void dfs(int u,int p)
{
	sz[u]=1;
	dp[u][0]=1;
	ndp[u][0]=1;
	for(int h=0;h<adj[u].size();h++)
	{
		int v=adj[u][h];
		if(v!=p)
		{
			dfs(v,u);
			for(int i=0;i<sz[u];i++)
			{
				for(int j=0;j<sz[v] && i+j+1<=k;j++)
				{
					ndp[u][max(i,j+1)]=max(ndp[u][max(i,j+1)],dp[u][i]+dp[v][j]);
				}
			}
			sz[u]+=sz[v];
			for(int i=0;i<sz[u];i++)
			{
				dp[u][i]=ndp[u][i];
			}
		}
	}
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<n-ans<<endl;
	return 0;
}