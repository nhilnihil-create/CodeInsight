#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

const int inf = 1e9;

vector<vector<int>> warshall_floyd(vector<vector<int>> dist) {
	int n = dist.size();

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	return dist;
}

int main() {
	int n, m, a, b, c;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, inf));

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--;
		b--;

		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}

	int ans = 0;
	auto dist2 = warshall_floyd(dist);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] != inf && dist[i][j] != dist2[i][j]) {
				ans++;
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	printf("%d: ", i+1);
	// 	for (int j = 0; j < n; j++) {
	// 		int x = dist[i][j];
	// 		printf("%2d ", x != inf ? x : -1);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	// for (int i = 0; i < n; i++) {
	// 	printf("%d: ", i+1);
	// 	for (int j = 0; j < n; j++) {
	// 		printf("%2d ", dist2[i][j]);
	// 	}
	// 	printf("\n");
	// }

	ans /= 2;
	cout << ans << endl;
	return 0;
}
