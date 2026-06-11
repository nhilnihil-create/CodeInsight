// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000, M = 2000;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int ii[M], jj[M], ww[M];
long long dp[N];

int main() {
	int n, m; cin >> n >> m;
	for (int h = 0; h < m; h++) {
		int i, j, w; cin >> i >> j >> w, i--, j--;
		ii[h] = i, jj[h] = j, ww[h] = w;
	}
	fill(dp, dp + n, -INF);
	dp[0] = 0;
	for (int k = 1; k <= n * 2; k++) {
		bool updated = false;
		for (int h = 0; h < m; h++) {
			int i = ii[h], j = jj[h];
			if (dp[i] != -INF) {
				long long d = dp[i] + ww[h];
				if (dp[j] < d) {
					dp[j] = d;
					if (j == n - 1)
						updated = true;
				}
			}
		}
		if (updated && k >= n) {
			cout << "inf\n";
			return 0;
		}
	}
	cout << dp[n - 1] << '\n';
	return 0;
}
