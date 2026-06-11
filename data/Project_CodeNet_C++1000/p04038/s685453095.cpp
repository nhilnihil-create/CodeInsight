#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2005;
const int mod = 1e9 + 7;

int n, k;
LL f[N][N], fac[N * N], inv[N * N], fav[N * N];

inline void Add(LL &x, LL y) {
	x += y;
	if (x >= mod) x -= mod;
}

inline LL C(LL x, LL y) {
	if (x < 0 || x < y) return 0;
	return (fac[x] * fav[y] % mod * fav[x - y] % mod);
}

int main() {
	cin >> n >> k;
	if (k == 1) return 0 * puts("1");
	fac[0] = fav[0] = 1;
	fac[1] = fav[1] = inv[1] = 1;
	for (int i = 2; i < N * N; ++i) {
		inv[i] = (-mod / i * inv[mod % i] % mod) + mod;
		fac[i] = fac[i - 1] * i % mod;
		fav[i] = fav[i - 1] * inv[i] % mod;
	}
	f[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (j < n) {
				Add(f[i][j + 1], f[i][j]);
			}
			if (i < j) {
				if ((n - i) * k - j + i - 1 >= 0)
					Add(f[i + 1][j], f[i][j] * C((n - i) * k - j + i - 1, k - 2) % mod);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		f[n][n] = f[n][n] * i % mod;
	}
	cout << f[n][n] << endl;
	return 0;
}

