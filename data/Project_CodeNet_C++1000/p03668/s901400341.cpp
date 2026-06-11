#include <bits/stdc++.h>
using namespace std;


//#define int long long 

const int N = 1e5 + 7;


vector <int> adj[N];

int dfs(int u, int p) {
	int x = 0;
	for(int v: adj[u]) if(v ^ p) {
		x ^= (1 + dfs(v, u));
	}
	return x;
}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << (dfs(1, 0) ? "Alice" : "Bob") << endl;
}