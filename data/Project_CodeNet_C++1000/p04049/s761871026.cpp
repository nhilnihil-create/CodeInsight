#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 2e3 + 10;
int n, k, cnt[maxn], l, t, ans;
vector <int> adj[maxn];

void dfs(int v, int par, int he) {
	cnt[he]++;
	if (he == l)
		++t;
	for (auto u: adj[v])
		if (u != par)
			dfs(u, v, he + 1);
	return;
}

int main(){
	cin >> n >> k;
	for (int i = 1, v, u; i < n; ++i) {
		cin >> v >> u;
		adj[--v].pb(--u);
		adj[u].pb(v);
	}
	l = (k + 1) / 2;
	ans = maxn;
	for (int i = 0, mx, sum; i < n; ++i) {
		memset(cnt, 0, sizeof(cnt));
		mx = 0;
		for (auto j: adj[i]) {
			t = 0;
			dfs(j, i, 1);
			mx = max(t, mx);
		}
		sum = 0;
		for (int f = k / 2 + 1; f <= n; ++f)
			sum += cnt[f];
		if (k & 1)
			sum -= mx;
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
