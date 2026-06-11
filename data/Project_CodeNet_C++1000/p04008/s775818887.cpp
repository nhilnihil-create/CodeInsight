#include<iostream>
#include<vector>
using namespace std;
vector<int>G[1<<17];
int n,K,a[1<<17];
vector<int>dk[1<<17];
int pk[1<<17];
void dfs(int u,int k)
{
	pk[k]=u;
	if(k>=K)
	{
		dk[pk[k-K]].push_back(u);
	}
	for(int i=0;i<G[u].size();i++)dfs(G[u][i],k+1);
}
int dp[1<<17];
int get(int,int);
int bfs(int u)
{
	dp[u]=1e9;
	int s=0;
	for(int i=0;i<G[u].size();i++)
	{
		s+=bfs(G[u][i]);
	}
	//dp[u]=min(dp[u],s+(int)G[u].size());
	s=0;
	for(int i=0;i<dk[u].size();i++)s+=dp[dk[u][i]];
	dp[u]=min(dp[u],s+(int)dk[u].size());
	if(1L*n*K<1e8)dp[u]=get(u,K-1);
	return dp[u];
}
int get(int u,int k)
{
	if(k<0)return dp[u]+1;
	int ans=dp[u]+1;
	int sum=0;
	for(int i=0;i<G[u].size();i++)
	{
		sum+=get(G[u][i],k-1);
	}
	return min(ans,sum);
}
main()
{
	cin>>n>>K;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
		if(i)G[a[i]].push_back(i);
	}
	dfs(0,0);
	bfs(0);
	cout<<get(0,K)+!!a[0]<<endl;
}