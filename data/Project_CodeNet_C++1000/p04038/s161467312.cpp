#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define MAXN 2005


int n, k;
LL f[MAXN][MAXN], fac[MAXN * MAXN], inf[MAXN * MAXN];
const int mod = 1e9 + 7, N = 4000000;

LL power(LL a, int b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    inf[0] = fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = fac[i - 1] * i % mod;
    inf[N] = power(fac[N], mod - 2);
    for (int i = N - 1; i >= 1; --i)
        inf[i] = inf[i + 1] * (i + 1) % mod;
}

LL C(int n, int m) {
    return fac[n] * inf[n - m] % mod * inf[m] % mod;
}

int main() {
    init();
    scanf("%d%d", &n, &k);
    if (k == 1) {
        puts("1");
        return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            if (!j)
                f[i][j] = f[i - 1][j]; //白球
            else
                f[i][j] = (f[i - 1][j] + f[i][j - 1] * C(n * k - (j - 1) * (k - 1) - i - 1, k - 2) % mod * (n - j + 1) % mod) % mod;
    printf("%lld\n", f[n][n]);
}