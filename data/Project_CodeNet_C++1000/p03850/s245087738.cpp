#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 100010;
LL A[MAXN], dp[MAXN][3];
int opt[MAXN], n, bak;
char buf[10];
void getmax(LL & x, LL y) { x < y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		if (i > 1) std::cin >> buf, opt[i] = *buf == '-';
		std::cin >> A[i];
	}
	memset(dp, 0xcf, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 2; ++j) {
			int t = j + opt[i];
			if (t <= 2)
				getmax(dp[i][t], dp[i - 1][j] + A[i] * (t & 1 ? -1 : 1));
		}
		getmax(dp[i][1], dp[i][2]);
		getmax(dp[i][0], dp[i][1]);
	}
	std::cout << dp[n][0] << std::endl;
	return 0;
}
