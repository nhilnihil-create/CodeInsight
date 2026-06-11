#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

void solve() {
    ll fact[200001], inv[200001];
    fact[0] = 1;
    rep(i,200000) fact[i + 1] = (fact[i] * (i + 1)) % MOD;
    rep(i,200001) inv[i] = mod_pow(fact[i], MOD - 2, MOD);
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    ll ans = 0;
    rep(i,H - A) {
        ll x = (fact[i + B - 1] * inv[i]) % MOD;
        x = (x * inv[B - 1]) % MOD;
        x = (x * fact[W - B - 1 + H - 1 - i]) % MOD;
        x = (x * inv[W - B - 1]) % MOD;
        x = (x * inv[H - 1 - i]) % MOD;
        ans = (ans + x) % MOD;
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
}
