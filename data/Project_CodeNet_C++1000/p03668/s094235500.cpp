#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

int grundy[maxn];

void dfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
		{
			dfs(u , v);
			grundy[v] ^= (grundy[u] + 1);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(0);

	cout << (grundy[0]? "Alice" : "Bob") << endl;
}




















