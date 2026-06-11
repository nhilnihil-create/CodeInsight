#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;


int main() {
	int N, W;
	cin >> N >> W;

	vector<int> w(N, 0), v(N, 0);
	long long w_base = 0;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
		if (i == 0) {
			w_base = w[i] - 1;
		}
		w[i] -= w_base;
	}

	int w_limit = 1 + N * 4;
	// i個目をチェック・j個格納・価値k
	VVVI dp(N+1, VVI(N+1, VI(w_limit, -99)));
	dp[0][0][0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = w_limit - 1; k >= 0; k--) {
				if (dp[i][j][k] < 0) {
					continue;
				}


				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

				int nw = k + w[i];
				long long real_nw = w_base * (j + 1) + nw;
// printf("  ijk: %d %d %2d: dp %3d, nw %3d, real %3lld\n", i, j, k, dp[i][j][k], nw, real_nw);

				if (real_nw <= W && nw < w_limit) {
// printf("  ok:  %3d %3d\n", dp[i+1][j+1][nw], dp[i][j][k] + v[i]);
					dp[i+1][j+1][nw] = max(dp[i+1][j+1][nw], dp[i][j][k] + v[i]);
				}
			}
		}
	}

	int ans = 0;
	for (auto v: dp[N]) {
		for (auto x: v) {
			ans = max(ans, x);
		}
	}

	cout << ans << endl;
	return 0;
}
