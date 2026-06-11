#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e3 + 7, MXA = 4e6 + 7;
long long M = 1e9 + 7;
int fc[MXA];
int rfc[MXA];
long long pw(int a, int b) {
	if (b == 0)
		return 1;
	int t = pw(a, b / 2);
	t = (t * t) % M;
	if (b % 2)
		t = (t * a) % M;
	return t;
}
int rk;
long long chs(int a, int b) {
	long long t = fc[b];
	t = (t * rk) % M;
	t = (t * pw(fc[b - a], M - 2)) % M;
	return t;
}
int n, k;
int dp[N][N];
int32_t main() {
	fc[0] = rfc[0] =  1;
	
	for (int i = 1; i < MXA; i++)
		fc[i] = (fc[i - 1] * i) % M;
	dp[0][0] = 1;
	cin >> n >> k;
	rk = pw(fc[k - 2], M - 2);
	if (k == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i <= n; i++)
		for (int j = i; j <= n; j++) {
			if (i + j == 0)
				continue;
			if (i > 0)
				dp[i][j] = dp[i - 1][j];
			if (j > i) {
				int tmp = i + j * (k - 1) - 1;
				dp[i][j] += (chs(k - 2, tmp) * dp[i][j - 1]) % M;
				dp[i][j] %= M;
//				cout << i << " " << j << " > " << dp[i][j] << " " << tmp << " " << (fc[tmp] * rfc[k - 2] % M) * rfc[tmp - (k - 2)] % M << endl;
			}
		}
	cout << (dp[n][n] * fc[n]) % M;
	return 0;
}