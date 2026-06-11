#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
int const M=2e5+10;
vector<int>adj[M];
int val[M],dp[M],zt[M],leaf[M],root;
void dfs(int v,int l)
{
	vector<int>tmp;
	if(adj[v].size()==1){
		leaf[v]=val[v];
		return;
	}
	for(int i=0;i<adj[v].size();i++)
	{
		int u=adj[v][i];
		if(u!=l)dfs(u,v);
		if(u==l)continue;
		zt[v]+=zt[u];
		leaf[v]+=leaf[u];
		tmp.pb(leaf[u]-zt[u]);
	}
	int res=leaf[v]-zt[v];
	if(val[v]>res)
	{
		cout<<"NO";
		exit(0);
	}
	dp[v]=res-val[v];
	if(v==root && dp[v]!=val[v])
	{
		cout<<"NO";
		exit(0);
	}
	zt[v]+=2*dp[v];
	int bad=0;
	for(int i=0;i<tmp.size();i++)
	{
		if(tmp[i]<=dp[v])continue;
		bad+=tmp[i]-dp[v];
	}
	if(bad>res-dp[v]*2)
	{
		cout<<"NO";
		exit(0);
	}
}
main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	if(n==2)
	{
		if(val[1]==val[2])cout<<"YES";
		else cout<<"NO";
		return 0;
	}
	root=1;
	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()!=1)root=i;
	}
	dfs(root,0);
	cout<<"YES";
}