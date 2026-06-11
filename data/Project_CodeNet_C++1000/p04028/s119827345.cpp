#include <bits/stdc++.h>

using namespace std;

int dp[5003][5003];
int n;
string s;

const int mod = 1e9 + 7;

int bPow(int n, int k) {
	if (k == 1) {
		return n;
	}
	if (k == 0) {
		return 1;
	}
	int cur = bPow(n, k / 2);
	if (k % 2 == 1) {
		return ( ( 1ll * cur * cur ) % mod * n ) % mod;
	}
	else {
		return (1ll * cur * cur) % mod;
	}
}

signed main() {
	cin >> n >> s;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				dp[i][j] = (1ll * dp[i-1][j] + 1ll * dp[i-1][j+1]) % mod;
				continue;
			}
			dp[i][j] = (1ll * dp[i-1][j+1] + 1ll * 2 * dp[i-1][j-1]) % mod;
			//cout << dp[i][j] << " " << i << " " << j << endl;  
		}
	}
	cout << 1ll * dp[n][s.length()] * bPow(bPow(2, s.length()), mod-2) % mod;
}