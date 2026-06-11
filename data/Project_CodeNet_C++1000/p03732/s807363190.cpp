#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> w(N), v(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}
	long long x = w[0];
	for (int i = 0; i < N; i++) {
		w[i] -= x;;
	}
	vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(200, vector<long long>(N + 1, 0)));
	for (int i = 0; i < N; i++) {
		for (long long j = 0; j < 200; j++) {
			for (int k = 0; k < i + 1; k++) {
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
				if (j >= w[i]) {
					dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j - w[i]][k] + v[i]);
				}
			}
		}
	}
	long long ans = 0;
	for (long long i = 0; i < 200; i++) {
		for (long long j = 0; j < N + 1; j++) {
			if (i + x * j <= W) {
				ans = max(ans, dp[N][i][j]);
			}
		}
	}
	cout << ans << endl;

	return 0;
}