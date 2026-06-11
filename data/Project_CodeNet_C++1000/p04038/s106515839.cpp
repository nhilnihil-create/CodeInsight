# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace IO {
    const int maxn(1 << 21 | 1);

    char ibuf[maxn], *iS, *iT, c;
    int f;

    inline char Getc() {
        return iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, maxn, stdin), (iS == iT ? EOF : *iS++)) : *iS++;
    }

    template <class Int> inline void In(Int &x) {
        for (f = 1, c = Getc(); c < '0' || c > '9'; c = Getc()) f = c == '-' ? -1 : 1;
        for (x = 0; c >= '0' && c <= '9'; c = Getc()) x = (x << 1) + (x << 3) + (c ^ 48);
        x *= f;
    }
}

using IO :: In;

const int maxn(2005);
const int maxm(maxn * maxn);
const int mod(1e9 + 7);

int n, k, f[maxn][maxn], fac[maxm], ifac[maxm], inv[maxm];

inline void Inc(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

inline int C(int x, int y) {
	if (y > x) return 0;
	return 1LL * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main() {
	In(n), In(k), f[1][0] = 1;
	if (k == 1) return puts("1"), 0;
	int mx = n * k;
	fac[1] = ifac[1] = fac[0] = ifac[0] = inv[1] = 1;
	for (int i = 2; i <= mx; ++i) {
		inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
		fac[i] = 1LL * fac[i - 1] * i % mod;
		ifac[i] = 1LL * ifac[i - 1] * inv[i] % mod;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			if (i > j) Inc(f[i][j], f[i - 1][j]);
			if (j) Inc(f[i][j], 1LL * f[i][j - 1] * C(mx - i - (j - 1) * (k - 1) - 1, k - 2) % mod);
		}
	printf("%lld\n", 1LL * f[n][n] * fac[n] % mod);
    return 0;
}