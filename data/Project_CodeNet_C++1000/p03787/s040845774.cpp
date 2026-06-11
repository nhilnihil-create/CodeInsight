#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< vector<int> > G;

void dfs(int cur, int par, vector<int>& col, bool& flag) {
	for (int nex : G[cur]) {
		if (nex == par) continue;
		if (col[nex] != -1) {
			if (col[nex] == col[cur]) flag = false;
			continue;
		}
		col[nex] = !col[cur];
		dfs(nex, cur, col, flag);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> col(n, -1);
	ll cnt1 = 0, cnt2 = n, cnt3 = 0;
	for (int i = 0; i < n; i++) {
		if (col[i] != -1) continue;
		col[i] = 0;
		if (G[i].empty()) {
			cnt2--;
			continue;
		}
		cnt1++;
		bool flag = true;
		dfs(i, -1, col, flag);
		cnt3 += flag;
	}

	cout << (ll)n * n - cnt2 * cnt2 + cnt1 * cnt1 + cnt3 * cnt3 << endl;
	return 0;
}
