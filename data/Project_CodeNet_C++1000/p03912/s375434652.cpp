#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> X(1e5 + 10, 0);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		++X[x];
	}

	vector<vector<int>> memo(M, vector<int>(2, 0));
	for (int i = 0; i < X.size(); ++i) {
		memo[i % M][0] += X[i] % 2;
		memo[i % M][1] += X[i] / 2;
	}

	int ans = 0;
	for (int i = 0; 2 * i <= M; ++i) {
		if (i == 0 || 2 * i == M) {
			ans += memo[i][0] / 2 + memo[i][1];
			continue;
		}

		int a = i, b = M - i;
		if (memo[a][0] < memo[b][0]) {
			swap(memo[a][0], memo[b][0]);
			swap(memo[a][1], memo[b][1]);
		}
		ans += memo[b][0];
		memo[a][0] -= memo[b][0];
		ans += min(memo[a][0], memo[b][1] * 2) + memo[a][1] + max(memo[b][1] * 2 - memo[a][0], 0) / 2;
	}
	cout << ans << endl;

	return 0;
}
