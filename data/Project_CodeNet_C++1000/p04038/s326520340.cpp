#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define N 2001
int n, k;
ll fac[N * N], inv[N * N], dp[N][N] = {1};
ll Qpow(ll x, ll n) {
    ll s = 1;
    while (n) {
        if (n & 1) s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s;
}
ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
    scanf("%d%d", &n, &k);
    if (k == 1) {
        puts("1");
        return 0;
    }
    for (int i = fac[0] = 1; i <= n * k; i++) fac[i] = fac[i - 1] * i % mod;
    inv[n * k] = Qpow(fac[n * k], mod - 2);
    for (int i = n * k; i; i--) inv[i - 1] = inv[i] * i % mod;
    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++) {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            ll s = C(k * (n - i) - (j - i) - 1, k - 2) + dp[i + 1][j];
            dp[i + 1][j] = dp[i][j] * s % mod;
        }
    printf("%lld", dp[n][n] * fac[n] % mod);
    return 0;
}