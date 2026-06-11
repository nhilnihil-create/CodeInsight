#include <cstdio>
const int MAXN = 2005, mod = 1e9 + 7;
inline int powmod(int a, int x) {
    long long cur = a, res = 1;
    while(x) {
        if(x & 1) res = (res * cur) % mod;
        cur = (cur * cur) % mod;
        x >>= 1;
    }
    return (int)res;
}
int n, k, f[MAXN][MAXN];
int fac[MAXN * MAXN], rev_fac[MAXN * MAXN];
inline int commod(int n, int m) {
    return ((((long long)fac[n] * rev_fac[m]) % mod) * rev_fac[n - m]) % mod;
}
int main() {
    fac[0] = 1;
    rev_fac[0] = powmod(fac[0], mod - 2);
    for(int i = 1; i < MAXN * MAXN; i++) {
        fac[i] = ((long long)fac[i - 1] * i) % mod;
        rev_fac[i] = powmod(fac[i], mod - 2);
    }
    scanf("%d%d", &n, &k);
    int ans;
    if(k == 1) {
        ans = 1;
    }
    else {
        for(int i = 0; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                if(i == 0 && j == 0) f[i][j] = 1;
                if(i - 1 >= 0) f[i][j] = f[i - 1][j];
                if(j > i) {
                    int t = ((long long)f[i][j - 1] * commod(i + j * (k - 1) - 1, k - 2)) % mod;
                    f[i][j] += t;
                    if(f[i][j] >= mod) f[i][j] -= mod;
                }
            }
        }
        ans = ((long long)fac[n] * f[n][n]) % mod;
    }
    printf("%d\n", ans);
    return 0;
}