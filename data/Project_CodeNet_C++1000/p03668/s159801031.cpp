#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[111111];
vi adj[111111];

void dfs(int u, int p)
{
	int xr=0;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		xr^=(dp[v]+1);
	}
	dp[u]=xr;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0,-1);
	cout<<(dp[0]>0?"Alice":"Bob")<<'\n';
}
