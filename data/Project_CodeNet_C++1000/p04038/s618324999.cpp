#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, MAXN = 4e6 + 1, mod = 1e9 + 7;
int fc[MAXN + 5], ifc[MAXN + 5], n, k, dp[N][N];
int power(int a, int b) {
	if (!b)
		return 1;
	int rtr = power(a, b / 2);
	if (b % 2)
		return 1ll * rtr * rtr % mod * a % mod;
	return 1ll * rtr * rtr % mod;
}
void Pre() {
	fc[0] = ifc[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fc[i] = 1ll * fc[i - 1] * i % mod;
		ifc[i] = power(fc[i], mod - 2);
	}
}
int ch(int x, int y) {
	return 1ll * fc[y] * ifc[x] % mod * ifc[y - x] % mod;
}
int main() {
	Pre();
	cin >> n >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
//			cout << "i = " << i << " j = " << j << endl;
			if (j > i)
				continue;
			if (i)
				dp[i][j] = dp[i - 1][j];
			if (j) {
//				cout << " : " << k - 2 << ", " << n * k - (j - 1) * (k - 1) - i << endl;
				dp[i][j] = (dp[i][j] + 1ll * dp[i][j - 1] * ch(k - 2, n * k - (j - 1) * (k - 1) - i - 1) % mod) % mod;
			}
//			cout << dp[i][j] << endl;
		}
	}
	cout << 1ll * dp[n][n] * fc[n] % mod;
	return 0;
}	
