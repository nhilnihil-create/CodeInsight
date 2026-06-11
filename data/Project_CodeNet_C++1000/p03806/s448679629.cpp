// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 40, A = 10, B = 10, INF = 0x3f3f3f3f;

int dp[A * N + 1][B * N + 1];

int main() {
	int n, ma, mb; cin >> n >> ma >> mb;
	for (int i = 0; i <= A * n; i++)
		for (int j = 0; j <= B * n; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int h = 0; h < n; h++) {
		int a, b, c; cin >> a >> b >> c;
		for (int i = A * n - a; i >= 0; i--)
			for (int j = B * n - b; j >= 0; j--) {
				int x = dp[i][j];
				if (x != INF)
					dp[i + a][j + b] = min(dp[i + a][j + b], x + c);
			}
	}
	int ans = INF;
	for (int k = 1, i, j; (i = k * ma) <= A * n && (j = k * mb) <= A * n; k++)
		ans = min(ans, dp[i][j]);
	cout << (ans != INF ? ans : -1) << '\n';
	return 0;
}
