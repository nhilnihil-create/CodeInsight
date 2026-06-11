#include <bits/stdc++.h>

using namespace std;

#define N 2000
#define MOD 1000000007

int n, k, fac[N * N + 5], facinv[N * N + 5], f[N + 5][N + 5];

int fpow(int x, int p) {
    int ret = 1;
    while (p) {
        if (p & 1) ret = 1LL * ret * x % MOD;
        x = 1LL * x * x % MOD;
        p >>= 1;
    }
    return ret;
}

int C(int n, int m) {
    if (n < m)
        return 0;
    return 1LL * fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}

int main() {
    scanf("%d%d", &n, &k);
    if (k == 1) {
        printf("1\n");
        return 0;
    }
    fac[0] = 1;
    for (int i = 1; i <= n * k; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    facinv[n * k] = fpow(fac[n * k], MOD - 2);
    for (int i = n * k; i >= 1; --i)
        facinv[i - 1] = 1LL * facinv[i] * i % MOD;
    for (int i = 1; i <= n; ++i)
        f[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            f[i][j] = (f[i - 1][j] + 1LL * f[i][j - 1] * (n - j + 1) % MOD * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2)) % MOD;
    printf("%d\n", f[n][n]);
    return 0;
}