#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MN = 5010;

int exp(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ret;
}
int inv(int x) {
    return exp(x, mod - 2);
}
int fact[MN], invf[MN];
int comb(int n, int k) {
    return 1LL * fact[n] * invf[k] % mod * invf[n - k] % mod;
}

int N, M, R;
string S;
int f[MN][MN], g[MN][MN];

int main() {
    fact[0] = 1;
    for(int i = 1; i < MN; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 0; i < MN; i++) {
        invf[i] = inv(fact[i]);
    }

    cin >> N >> S;

    M = S.size();
    R = N - M;

    f[0][0] = 1;
    for(int i = 2; i <= R; i++) {
        for(int j = 1; j <= M + R; j++) {
            f[i][j] += 2LL * f[i - 2][j - 1] % mod;
            f[i][j] %= mod;
            f[i][j] += 4LL * f[i - 2][j] % mod;
            f[i][j] %= mod;
            f[i][j] += 2LL * f[i - 2][j + 1] % mod;
            f[i][j] %= mod;
        }
    }

    g[0][0] = 1;
    for(int i = 1; i <= R; i++) {
        for(int j = 0; j <= R; j++) {
            g[i][j] += 2LL * g[i - 1][j + 1] % mod;
            g[i][j] %= mod;
            g[i][j] += g[i - 1][max(0, j - 1)];
            g[i][j] %= mod;
        }
    }

    int ans = 0;
    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= M; j++) {
            ans += 1LL * g[i][0] * f[R - i][j] % mod * comb(M, j) % mod;
            ans %= mod;
        }
    }
    printf("%d", ans);
}
