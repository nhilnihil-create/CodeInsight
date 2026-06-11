#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
ll fac[N];
ll qpow(ll x, ll k) {
    ll r = 1;
    while(k) {
        if(k & 1) r = r * x % MOD;
        k >>= 1;
        x = x * x % MOD;
    }
    return r;
}
ll divd(ll x, ll y) {
    return x * qpow(y, MOD - 2) % MOD;
}
ll C(ll x, ll y) {
    return divd(fac[x], fac[y] * fac[x-y] % MOD);
}
int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    fac[0] =1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ll ans = C(h+w-2, h-1);
    for(int i = h - a; i <= h - 1; i++) {
        int x = i, y = b - 1;
        ll res = C(x+y, x) * C(h+w-3-x-y, h-1-x) % MOD;
        ans -= res;
        if(ans < 0) ans += MOD;
    }
    cout << ans << endl;
    return 0;
}