#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<int> adj[100005];
int a[100005];

bool solve(int node, int fa)
{
	if(adj[node].size()==1) return true;
	int ttake=0;
	int mmax=0;
	for(auto i:adj[node])
	{
		if(i==fa) continue;
		if(!solve(i, node)) return false;
		ttake+=a[i];
		mmax=max(mmax, a[i]);
	}
	if(ttake<a[node]) return false;
	if(ttake>2*a[node]) return false;
	if(mmax>a[node]) return false;
	a[node]-=(ttake-a[node]);
	if(node==fa)
		if(a[node]==0) return true;
		else return false;
	else return true;
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(n==2)
	{
		if(a[1]!=a[2]) cout<<"NO";
		else cout<<"YES";
		return 0;
	}
	for(int i=1; i<n; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1; i<=n; i++)
	{
		if(adj[i].size()>1)
		{
			if(solve(i,i)) cout<<"YES";
			else cout<<"NO";
			return 0;
		}
	}
}