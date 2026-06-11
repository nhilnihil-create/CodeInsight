// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int timer;
int level[N], par[N][22], tin[N], tout[N];
vector<int> adj[N];

void dfs(int u, int p) {
	tin[u] = ++timer;
	level[u] = level[p] + 1;
	par[u][0] = p;
	for(int v : adj[u]) {
		if(v == p) continue;
		dfs(v, u);
	}
	tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	for(int i = 1; i < 22; i++) {
		for(int j = 0; j < n; j++) {
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}

	auto lca = [&](int u, int v) {
		if(is_ancestor(u, v)) return u;
		if(is_ancestor(v, u)) return v;
		for(int i = 21; i >= 0; i--) {
			if(!is_ancestor(par[u][i], v)) {
				u = par[u][i];
			}
		}
		return par[u][0];
	};

	int c1 = 0, c2 = 0;

	for(int i = 0; i < n; i++) {
		int d1 = level[i] + level[0] - 2 * level[lca(i, 0)];
		int d2 = level[i] + level[n - 1] - 2 * level[lca(i, n - 1)];
		if(d1 <= d2) c1++;
		else c2++;
	}
	if(c1 > c2) cout << "Fennec";
	else cout << "Snuke";
	return 0;
}
