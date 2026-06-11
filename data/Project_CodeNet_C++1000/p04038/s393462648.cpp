#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return mult(a, b_pow(a, b - 1));
	}
	return b_pow(mult(a, a), b >> 1);
}

const int MX = 4e6 + 10;
int f[MX], rf[MX];

int C(int n, int k) {
	if (n < 0 || k < 0 || n < k) {
		return 0;
	}
	return mult(f[n], mult(rf[k], rf[n - k]));
}

const int N = 2010;
int dp[N][N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	f[0] = 1;
	for (int i = 1; i <= 4e6; i++) {
		f[i] = mult(f[i - 1], i);
	}
	rf[4000000] = b_pow(f[4000000], MOD - 2);
	for (int i = 4e6 - 1; i >= 0; i--) {
		rf[i] = mult(rf[i + 1], i + 1);
	}
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 1 << '\n';
		exit(0);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (!j) {
				dp[i][j] = 1;
				continue;
			}
			if (i > 0) {
				add(dp[i][j], dp[i - 1][j]);
			}
			if (j > 0) {
				add(dp[i][j], mult(dp[i][j - 1], C(i + j * (k - 1) - 1, k - 2)));
			}
		}
	}
	int ans = dp[n][n];
	for (int i = 2; i <= n; i++) {
		ans = mult(ans, i);
	}
	cout << ans << '\n';
}	