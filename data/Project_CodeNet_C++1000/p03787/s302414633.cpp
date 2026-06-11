#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100010;
int N, M;
vector<int> adj[MAXN];
int col[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int nIsolated = 0;
	int nBipartite = 0;
	int nOther = 0;
	fill_n(col + 1, N, -1);
	for (int s = 1; s <= N; s++) {
		if (col[s] != -1) continue;
		vector<int> q = {s};
		col[s] = 0;
		bool isBip = true;
		for (size_t i = 0; i < q.size(); i++) {
			int cur = q[i];
			int colNxt = 1 - col[cur];
			for (size_t j = 0; j < adj[cur].size(); j++) {
				int nxt = adj[cur][j];
				if (col[nxt] == -1) {
					col[nxt] = colNxt;
					q.push_back(nxt);
				} else {
					isBip &= (col[nxt] == colNxt);
				}
			}
		}
		if (q.size() == 1) {
			nIsolated++;
		} else if (isBip) {
			nBipartite++;
		} else {
			nOther++;
		}
	}

	ll ans = 0;
	ans += ll(2) * nIsolated * N - ll(nIsolated) * nIsolated;
	ans += ll(2) * nBipartite * nBipartite;
	ans += ll(nOther) * nOther;
	ans += ll(2) * nOther * nBipartite;
	cout << ans << endl;

	return 0;
}
