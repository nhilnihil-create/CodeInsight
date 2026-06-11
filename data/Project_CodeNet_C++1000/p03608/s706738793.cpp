#include "bits/stdc++.h"
using namespace std;
const int INF = 1001001001;
int main() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> r(R);
	vector<vector<int>> dist(N, vector<int>(N, INF));
	for (int n = 0; n < R; ++n) {
		cin >> r[n];
		r[n]--;
	}
	for (int n = 0; n < M; ++n) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		dist[b][a] = c;
		dist[a][b] = c;
	}
	//わーしゃるふろいど
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 1e9;
	vector<int> v;
	for (int n = 0; n < R; ++n) {
		v.push_back(n);
	}
	map<vector<int>, int>mp;
	do {
		int memo = 0;
		for (int i = 0; i < R - 1; ++i) {
			memo += dist[r[v[i]]][r[v[i + 1]]];
		}
		ans = min(ans, memo);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}