#include "bits/stdc++.h"
using namespace std;
const int INF = 1001001001;
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dist(N, vector<int>(N, INF));
	for (int n = 0; n < N; ++n) {
		dist[n][n] = 0;
	}
	vector<int>X(M); 
	vector<int>Y(M); 
	vector<int>Z(M);
	for (int n = 0; n < M; ++n) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		X[n] = a;
		Y[n] = b;
		Z[n] = c;
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

	int ans = 0;
	for (int n = 0; n < M; ++n) {
		bool b = true;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (dist[i][j] == (dist[i][X[n]] + Z[n]+ dist[Y[n]][j])) {
					b = false;
				}
			}
		}
		if (b) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}