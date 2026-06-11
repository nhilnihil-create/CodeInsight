#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 2020;
const int mod = 1e9 + 7;

int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int fac[MAXN * MAXN];
int binom (int x, int y) { return fac[x] * inv(fac[y]) % mod * inv(fac[x - y]) % mod; }

int n, k;
int dp[MAXN][MAXN];

signed main () {
    n = read(), k = read();
    if (k == 1) { puts("1"); return 0; }
    int i, j;
    dp[0][0] = fac[0] = 1;
    for (i = 1; i <= n * k; i++) fac[i] = fac[i - 1] * i % mod;
    for (i = 1; i <= n; i++) for (j = 0; j <= i; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j) 
            dp[i][j] += dp[i][j - 1] * (n - j + 1) % mod * binom(n * k - i - 1 - (j - 1) * (k - 1), k - 2) % mod, dp[i][j] %= mod;
    }
    printf("%lld\n", dp[n][n]);
    return 0;
}