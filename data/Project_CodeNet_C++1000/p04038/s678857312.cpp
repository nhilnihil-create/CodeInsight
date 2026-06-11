#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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
int fact[5000010], invf[5000010];
int comb(int n, int k) {
    return 1LL * fact[n] * invf[k] % mod * invf[n - k] % mod;
}
int H(int n, int k) {
    return comb(n + k - 1, k);
}

int N, K;

int cc[2010][2010];
int dp(int n, int r) {
    if(n == -1) return 1;
    int &ret = cc[n][r];
    if(ret != -1) return ret;

    ret = 0;

    int rem = (N - r) - (N - 1 - n);
    int len = (N - r) * (K - 1) + (N - 1 - n);

    if(rem) {
        ret += dp(n - 1, r);
        ret %= mod;
    }
    if(r) {
        ret += 1LL * r * H(len + 1, K - 2) % mod * dp(n, r - 1) % mod;
        ret %= mod;
    }
    return ret;
}

int main() {
    fact[0] = 1;
    for(int i = 1; i < 5000010; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 0; i < 5000010; i++) {
        invf[i] = inv(fact[i]);
    }

    cin >> N >> K;

    if(K == 1) {
        printf("1");
        return 0;
    }

    memset(cc, -1, sizeof(cc));
    printf("%d", dp(N - 1, N));
}
