#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long dp[1000000][5], a[1000000], n;
char op[1000000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; if (i != n - 1)cin >> op[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++)dp[i][j] = -1LL << 62;
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (dp[i][j] == -1LL << 62)continue;
			if (i == 0 || op[i - 1] == '+') {
				if (j % 2 == 0) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
					if (j >= 1)dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + a[i]);
				}
				if (j % 2 == 1) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - a[i]);
					if (j >= 1)dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] - a[i]);
				}
			}
			else {
				if (j % 2 == 0) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - a[i]);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - a[i]);
					if (j >= 1)dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] - a[i]);
				}
				if (j % 2 == 1) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
					if (j >= 1)dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + a[i]);
				}
			}
		}
	}
	cout << max(dp[n][0], max(dp[n][1], max(dp[n][2], dp[n][3]))) << endl;
	return 0;
}