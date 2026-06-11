#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

vector<int> adj[N], con[N];
int chk[N], vis[N], cnt;
long long val[N];
map<long long, int> M;

void dfs(int u) {
	for (int v : adj[u]) {
		if (chk[v]) continue;
		chk[v] = cnt;
		dfs(v);
	}
}

void DFS(int u) {
	for (int v : con[u]) {
		if (vis[v]) continue;
		vis[v] = cnt;
		DFS(v);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, K, L; cin >> n >> K >> L;
	for (int i = 0; i < K; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < L; i++) {
		int u, v; cin >> u >> v;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		chk[i] = ++cnt;
		dfs(i);
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = ++cnt;
		DFS(i);
	}
	for (int i = 1; i <= n; i++) {
		val[i] = chk[i] * 1000000LL + vis[i];
		M[val[i]]++;
	}
	for (int i = 1; i <= n; i++) cout << M[val[i]] << " \n"[i == n];
	return 0;
}

