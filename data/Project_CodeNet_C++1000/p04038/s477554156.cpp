#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int mod = 1e9 + 7, N = 2010;
typedef long long ll;
ll n, K, f[N][N], fac[N * N], inv[N * N];

ll quick_pow(ll a, ll b) {
	ll ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
	} return ret;
}

ll C(ll n, ll m) {
	if (!m) return 1;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	cin >> n >> K;
	
	if (K == 1) {
		puts("1"); return 0;
	}
	
	fac[0] = inv[0] = 1;
	rep(i, 1, n * K) fac[i] = fac[i - 1] * i % mod;
	inv[n * K] = quick_pow(fac[n * K], mod - 2);
	for (int i = n * K; i >= 1; i--) inv[i - 1] = inv[i] * i % mod;
	
	f[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 0, i) {
			f[i][j] = f[i - 1][j];
			if (j)
				f[i][j] = (f[i][j] + f[i][j - 1] * (n - j + 1) % mod * C(n * K - i - (j - 1) * (K - 1) - 1, K - 2) % mod) % mod;
		}
	}
	printf("%lld\n", f[n][n]);
	return 0;
}
