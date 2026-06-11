#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 2005;
const int MOD = 1000000007;

llint n, k;
llint dp[MAXN][MAXN], f[MAXN*MAXN], inv[MAXN*MAXN], r[MAXN*MAXN];

inline llint add (llint x, llint y) {
    x += y;
    if (x >= MOD) return x - MOD; return x;
}

void precompute () {
    f[0] = inv[0] = 1;
    for (int i=1; i<n*k; i++) {
        if (i == 1) r[i] = 1; else r[i] = (MOD - (MOD / i * r[MOD % i]) % MOD) % MOD;
        f[i] = f[i-1] * i % MOD;
        inv[i] = inv[i-1] * r[i] % MOD;
    }
}

llint nck (llint n, llint k) {
    return f[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void calc () {
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        llint curr = 0;
        for (int j = i; j >= 1; j--) {
            if (j > 1) curr = add(curr, dp[i-1][j-1]);
            dp[i][j] = curr * nck(k*i - j - 1, k-2) % MOD;
            dp[i][0] = add(dp[i][0], dp[i][j]);
        }
    }
}

int main () {
    cin >> n >> k;
    if (n == 1 || k == 1) {
        cout << 1;
        return 0;
    }
    precompute();
    calc();
    cout << dp[n][0] * f[n] % MOD;
    return 0;
}
