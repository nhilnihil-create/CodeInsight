#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2000 + 10;
constexpr int MOD = 1e9 + 7;

long long dp[N][N], fact[N * N], n, k;

long long mypow (long long a, long long b) {
    return b ? (mypow (a * a % MOD, b >> 1) * (b & 1 ? a : 1)) % MOD : 1;
}

long long ch (long long a, long long b) {
    return (fact[a] * mypow (fact[b] * fact[a - b] % MOD, MOD - 2)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << '\n';
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i < N * N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == 0) {
                if (j == 0)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = ch (j * (k - 1) - 1, k - 2) * dp[i][j - 1];
                    dp[i][j] %= MOD;
                }
                continue;
            }
            dp[i][j] = dp[i - 1][j] + ch (i + j * (k - 1) - 1, k - 2) * dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << (dp[n][n] * fact[n]) % MOD << '\n';
    return 0;
}
