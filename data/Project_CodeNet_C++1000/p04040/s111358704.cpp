#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MN = 200010;

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

int H, W, A, B;

int main() {
    fact[0] = 1;
    for(int i = 1; i < MN; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 0; i < MN; i++) {
        invf[i] = inv(fact[i]);
    }

    cin >> H >> W >> A >> B;

    int ans = 0;
    for(int i = 0; i <= H - A - 1; i++) {
        ans += 1LL * comb(B - 1 + i, B - 1) * comb(W - B - 1 + H - 1 - i, W - B - 1) % mod;
        ans %= mod;
    }
    cout << ans;
}
