#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
int n,k;
vector<int>g[2005];
int sz[2005],dp[2005][2005],ndp[2005][2005];
void dfs(int u,int p)
{
	sz[u]=1;
	dp[u][0]=1;
	ndp[u][0]=1;
	for(int V=0;V<g[u].size();V++)
	{
		int v=g[u][V];
		if(v!=p)
		{
			dfs(v,u);
			for(int i=0;i<sz[u];i++)
				for(int j=0;j<sz[v]&&i+j+1<=k;j++)
					ndp[u][max(i,j+1)]=max(ndp[u][max(i,j+1)],dp[u][i]+dp[v][j]);
				sz[u]+=sz[v];
				for(int i=0;i<n;i++)
					dp[u][i]=ndp[u][i];
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
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,1);
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=0;j<=k;j++)
			ans=max(ans,dp[i][j]);
	cout<<n-ans;
	return 0;
}