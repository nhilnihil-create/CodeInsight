#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int, int>
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll ans, cnt, gr[N];
ll a[N];

vector<int> adj[N];

void DFS(int v, int p = -1)
{
	//par[v] = p;
	gr[v] = 0;

	for(auto u : adj[v])
	{
		if(u == p)continue;
		DFS(u, v);
		gr[v] ^= (gr[u] + 1);
	}
	return ;
}

/*
void dfs(int v, int p = -1)
{
	if(p != -1 && mark[p] && !mark[v])ans ^= (gr[v] + 1);
	for(auto u : adj[v])
	{
		if(u == p)continue;
		dfs(u, v);
	}
	return ;
}
*/

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while(t--)
	{
		int ted = 0, n, root = 0; cin >> n;
		
		/*for(int i=0; i<n; i++){
			cin >> a[i];
			if(a[i])root = i, ted ++;
		}
		if(ted == 0)return cout << 1/0 << endl, 0;
		if(ted > 1)return cout << 1/0 << endl, 0;
		*/

		for(int i=0; i<n; i++)adj[i].clear();
		for(int i=0; i<n-1; i++)
		{
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		DFS(root);
		if(gr[root])cout << "Alice\n";
		else cout << "Bob\n";
	}

}	