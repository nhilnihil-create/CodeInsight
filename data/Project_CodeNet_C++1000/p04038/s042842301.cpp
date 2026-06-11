#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2010, md = 1e9 + 7;
int n, k;
int dp[2 * MAXN][MAXN], fact[MAXN * MAXN], inv_fact[MAXN * MAXN];
int combination(int k, int n) {
    if (k > n)
        return 0;
    return (fact[n] * inv_fact[k] % md) * inv_fact[n - k] % md;
}  
int power(int n, int p) {
    int res = 1;
    for (;p; p >>= 1, n = n * n % md)
        if (p & 1)
            res = res * n % md;
    return res;
}
int32_t main () {
    fact[0] = 1;
    for (int i = 1; i < MAXN * MAXN; ++i)
        fact[i] = fact[i - 1] * i % md;
    inv_fact[MAXN * MAXN - 1] = power(fact[MAXN * MAXN - 1], md - 2);
    for (int i = MAXN * MAXN - 1; i; --i)
        inv_fact[i - 1] = inv_fact[i] * i % md;
    cin >> n >> k;
    if (k == 1)
        return cout << 1, 0;
    dp[0][0] = 1;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j <= min(n, i); ++j) {
            if (j < n) {
                dp[i + 1][j + 1] += dp[i][j];
                if (dp[i + 1][j + 1] >= md)
                    dp[i + 1][j + 1] %= md;
            }
            if (j) {
                dp[i + 1][j - 1] += dp[i][j] * combination(k - 2, n * k - k * (i - j) / 2 - j - 1) % md;
                if (dp[i + 1][j - 1] >= md)
                    dp[i + 1][j - 1] %= md;
            }
            // cout << i << ' ' << j << '\n';
        }
    }
    for (int i= 1; i <= n; ++i)
        dp[2 * n][0] = dp[2 * n][0] * i % md;
    cout << dp[2 * n][0];
    return 0;
}