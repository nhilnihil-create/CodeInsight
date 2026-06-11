#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> f;

void dfs(vector<int>& res, int p) {
	f[p] = true;
	res.push_back(p);
	for (auto x : g[p]) {
		if (!f[x]) {
			dfs(res, x);
			return;
		}
	}
}

vector<int> solve() {
	int N, M; cin >> N >> M;
	g.resize(N);
	f.resize(N, false);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; ; i++) {
		if (g[i].size() == 1) {
			vector<int> res;
			dfs(res, i);
			return res;
		} else if (g[i].size()) {
			vector<int> l, r{i};
			f[i] = f[g[i][1]] = true;
			dfs(r, g[i][0]);
			dfs(l, g[i][1]);
			reverse(l.begin(), l.end());
			copy(r.begin(), r.end(), back_inserter(l));
			return l;
		}
	}
}

int main() {
	auto res = solve();
	cout << res.size() << endl;
	for (int i = 0; i < int(res.size()); i++) {
		if (i) cout << " ";
		cout << res[i] + 1;
	}
	cout << endl;
}