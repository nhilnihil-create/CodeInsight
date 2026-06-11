#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
vector <int> G[N];
int f[N];

void dfs(int u, int p) {
	for (int v: G[u]) if (v != p) {
		dfs(v, u);
		f[u] ^= (f[v] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);

	printf(f[1] > 0 ? "Alice\n" : "Bob\n");
}