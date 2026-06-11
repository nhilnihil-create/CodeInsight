#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k, l; cin >> n >> k >> l;
	vector<vector<int>> g1(n);
	vector<vector<int>> g2(n);
	for (int i = 0; i < k; i++) {
		int p, q; cin >> p >>q;
		p--; q--;
		g1[p].push_back(q);
		g1[q].push_back(p);
	}
	vector<int> vis1(n, 0);
	int cnt = 0;
	function<void(int)> dfs1 = [&](int u) {
		if (vis1[u]) return;
		vis1[u] = cnt;
		for (auto v : g1[u]) dfs1(v);
	};
	for (int i = 0; i < n; i++) {
		if (!vis1[i]) {
			cnt++;
			dfs1(i);
		}
	}
	for (int i = 0; i < l; i++) {
		int r, s; cin >> r >> s;
		r--; s--;
		g2[r].push_back(s);
		g2[s].push_back(r);
	}
	vector<int> vis2(n, 0);
	vector<pair<int, int>> ccc;
	cnt = 0;
	function<void(int)> dfs2 = [&](int u) {
		if (vis2[u]) return;
		vis2[u] = cnt;
		ccc.emplace_back(vis1[u], u);
		for (auto v : g2[u]) dfs2(v);
	};
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis2[i]) {
			cnt++;
			ccc.clear();
			dfs2(i);
			sort(ccc.begin(), ccc.end());
			for (int i = 0; i < ccc.size(); ) {
				int k;
				for (k = i; k < ccc.size() && ccc[k].first == ccc[i].first; k++);
				for (int j = i; j < k; j++) ans[ccc[j].second] = k - i;
				i = k;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
	return 0;
}
