#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	int n = ri(), m1 = ri(), m2 = ri();
	int dp[401][401];
	for (auto &i : dp) for (auto &j : i) j = 1000000000;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int a = ri(), b = ri(), c = ri();
		for (int j = 400 - a; j >= 0; j--) for (int k = 400 - b; k >= 0; k--)
			dp[j + a][k + b] = std::min(dp[j + a][k + b], dp[j][k] + c);
	}
	int res = 1000000000;
	for (int i = 1; m1 * i <= 400 && m2 * i <= 400; i++) res = std::min(res, dp[m1 * i][m2 * i]);
	printf("%d\n", res == 1000000000 ? -1 : res);
	return 0;
}
