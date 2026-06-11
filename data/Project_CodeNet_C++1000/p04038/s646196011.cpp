#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
const int maxn = 2005, mod = 1e9 + 7;

int n, k, m, fac[maxn * maxn], ifac[maxn * maxn], f[maxn][maxn];

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

inline void inc(int &a, int b) {a += b; if (a >= mod) a -= mod;}
inline int C(int n, int m)
{
	return (lint)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main()
{
	n = gi(); k = gi();
	if (k == 1) return puts("1"), 0;

	m = n * k;
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= m; ++i) fac[i] = (lint)fac[i - 1] * i % mod;
	for (int i = 2; i <= m; ++i) ifac[i] = (lint)(mod - mod / i) * ifac[mod % i] % mod;
	for (int i = 1; i <= m; ++i) ifac[i] = (lint)ifac[i - 1] * ifac[i] % mod;

	f[1][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			if (i > j) inc(f[i][j], f[i - 1][j]);
			if (j) inc(f[i][j], (lint)f[i][j - 1] * C(m - i - (j - 1) * (k - 1) - 1, k - 2) % mod);
		}

	printf("%lld\n", (lint)f[n][n] * fac[n] % mod);
	
	return 0;
}
