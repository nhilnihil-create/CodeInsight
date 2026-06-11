#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << (x) << endl
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

inline void File() {
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
}

const int N = 5e3 + 10, mod = 1e9 + 7;
char s[N]; int n, len, dp[N][N];

inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }

inline int qpow(int a, int b) {
	static int res;
	for (res = 1; b; b >>= 1, a = 1ll * a * a % mod)
		if (b & 1) res = 1ll * res * a % mod;
	return res;
}

int main() {

	cin >> n, scanf("%s", s + 1), len = strlen(s + 1);

	dp[0][0] = 1;
	For(i, 0, n) For(j, 0, i) {
		dp[i + 1][j + 1] = add(dp[i + 1][j + 1], 2ll * dp[i][j] % mod);
		dp[i + 1][max(j - 1, 0)] = add(dp[i + 1][max(j - 1, 0)], dp[i][j]);
	}

	int ans = 1ll * dp[n][len] * qpow(qpow(2, len), mod - 2) % mod;

	return cout << ans << endl, 0;
}
