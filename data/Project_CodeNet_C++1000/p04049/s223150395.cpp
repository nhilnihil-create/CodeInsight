#include<bits/stdc++.h>
using namespace std;
const int maxn = 2020;
using arr = array<int, maxn>;
int n, k, res = 1<<30, sz[maxn];
vector<int> g[maxn];

arr dfs(int v, int p) {
	sz[v] = 1;
	arr dp;
	fill(begin(dp), end(dp), 1);
	for(auto i : g[v]) if(i != p) {
		arr t = dfs(i, v);
		for(int i = k; i; i--) t[i] = t[i-1];t[0] = 0;
		arr ndp = dp;
		for(int a = 0; a <= sz[v]; a++)
			for(int b = 0; b <= sz[i] && a+b <= k; b++) {
				ndp[max(a, b)] = max(ndp[max(a, b)], dp[a] + t[b]);
			}
		dp = ndp;
		for(int i = 1; i <= k; i++) dp[i] = max({t[i], dp[i], dp[i-1]});
		sz[v] += sz[i];
	}
	res = min(res, n - dp[k]);
	return dp;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	dfs(1, 1);
	cout << res;
}
