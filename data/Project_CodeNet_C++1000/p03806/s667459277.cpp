#include <iostream>
using namespace std;
int main() {
	int n, ma, mb;
	scanf("%d%d%d", &n, &ma, &mb);
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	int dp[405][405];
	fill(dp[0], dp[0] + 405 * 405, 1e9);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 404; j >= 0; j--) {
			if (j < a[i]) break;
			for (int k = 404; k >= 0; k--) {
				if (k < b[i]) break;
				dp[j][k] = min(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
			}
		}
	}
	int ans = 1e9;
	int k = min(400 / ma, 400 / mb);
	for (int i = 1; i <= k; i++) ans = min(ans, dp[i * ma][i * mb]);
	printf("%d\n", ans == 1e9 ? -1 : ans);
	return 0;
}