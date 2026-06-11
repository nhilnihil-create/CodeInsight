#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

int ant, n, k;

static int dfs(int u) {
	if (g[u].empty()) return 0;

	int t, mx(0);
	for (auto v: g[u]) {	
		t = dfs(v) + 1;
		mx = max(mx, t % k);
		if (t == k && u != 1)
			ant+= 1; }

	return mx; }

int main() {
#ifdef HOME
	freopen("agc4d.in", "r", stdin);
	freopen("agc4d.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;

	cin >> n >> k >> t;
	if (t != 1)
		ant+= 1;
	for (int i = 2; i <= n; ++i) {
		cin >> t;
		g[t].push_back(i); }

	dfs(1);

	cout << ant << endl;

	return 0; }
