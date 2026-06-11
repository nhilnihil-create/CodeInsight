#include <bits/stdc++.h>

using namespace std;

const int N = (int)5000 + 7;
const int mod = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a > mod) a -= mod;
	return a;
}

int mul(int a, int b) {
	return (a * 1LL * b) % mod;
}

int n;
string s;
int dp[N][N];

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = mul(res, a);
		a = mul(a, a);
		n >>= 1;
	}
	return res;
}

main() {
	scanf("%d", &n);
	cin >> s;
	int len = s.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i + 1][j + 1] = add(dp[i + 1][j + 1], add(dp[i][j], dp[i][j]));
			if (j - 1 >= 0) dp[i + 1][j - 1] = add(dp[i + 1][j - 1], dp[i][j]);
			else dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
		}
	}
	int ans = mul(dp[n][len], binpow(binpow(2, len), mod - 2));
	printf("%d", ans);
}
