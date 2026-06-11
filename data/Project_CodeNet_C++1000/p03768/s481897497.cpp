#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int long long

const int N = 1e5 + 5, K = 11;

int dp[N][K];
int v[N], c[N], d[N];
vector<int> g[N];

void dfs(int u, int dist, int it) {
	if (dp[u][dist] != -1) return;
	dp[u][dist] = it;
	for (int &v : g[u]) {
		if (dist > 0) {
			dfs(v, dist - 1, it);
		}
	}
}
				
int32_t main() {
	fast_cin();  
	int n, m; cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> v[i] >> d[i] >> c[i];
	}
	memset(dp, -1, sizeof dp);
	for (int i = q - 1; i >= 0; --i) {
		dfs(v[i], d[i], i);
	}
	for (int v = 1; v <= n; ++v) {
		int ans = -1;
		for (int dist = 0; dist < K; ++dist) {
			ans = max(ans, dp[v][dist]);
		}
		cout << (ans == -1 ? 0 : c[ans]) << endl;
	}
	return 0;
}