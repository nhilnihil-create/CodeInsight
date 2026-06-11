#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const int MAXN = 1e5 + 21;

int n, k, ans;
int a[MAXN];
vector <int> adj[MAXN];
int g[MAXN];
bool mark[MAXN], b[MAXN];

void dfs(int v) {
	mark[v] = true;
	g[v] = 1;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
			g[v] = max(g[v], g[u] + 1);
		}
	}
	if (g[v] == k && !b[v]) {
		ans++;
		g[v] = 0;
	}
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
	b[1] = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		adj[a[i]].pb(i);
		if (a[i] == 1)
			b[i] = true;
	}

	dfs(1);
	
    if (a[1] ^ 1)
		ans++;
	
    cout << ans << '\n';
	return 0;
}
