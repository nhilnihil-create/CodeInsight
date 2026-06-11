#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

const int inf = 1e9;

vector<vector<int>> warshall_floyd(vector<vector<int>> costs) {
	int n = costs.size();
	for (int i = 0; i < n; i++) {
		costs[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	return costs;
}

int main() {
	int N, M, R;
	cin >> N >> M >> R;

	vector<int> r(R);
	for (int i = 0; i < R; i++) {
		cin >> r[i];
		r[i]--;
	}

	vector<vector<int>> costs(N, vector<int>(N, inf));
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		costs[a][b] = c;
		costs[b][a] = c;
	}

	costs = warshall_floyd(costs);
	sort(r.begin(), r.end());

	long long ans = inf;
	do {
		long long dist = 0;
		for (int i = 1; i < R; i++) {
			dist += costs[r[i-1]][r[i]];
		}
		ans = min(ans, dist);
	} while (next_permutation(r.begin(), r.end()));

	cout << ans << endl;
	return 0;
}
