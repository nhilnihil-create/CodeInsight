#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, ans, dist[105][105];
vector<pair<int, pair<int, int>>> edgeList;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = 1e9;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
		edgeList.push_back({a, {b, c}});
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	ans = m;
	for (int i = 0; i < m; i++) {
		int u = edgeList[i].first, v = edgeList[i].second.first, w = edgeList[i].second.second;
		if (w == dist[u][v]) {
			ans--;
		}
	}

	cout << ans << '\n';

	return 0;
}