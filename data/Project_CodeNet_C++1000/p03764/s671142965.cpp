#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
ll qpow(ll x, ll k) {
    ll r = 1;
    while(k) {
        if(k & 1) r = r * x % MOD;
        k >>= 1;
        x = x * x % MOD;
    }
    return r;
}
ll x[N], y[N], n, m;
void up(ll& a, ll b) {
    a += b;
    a %= MOD;
}
int main() {
    cin >> n >> m;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> y[i];
    }
    for(int i = 1; i < m; i++) {
        ans += 1LL * i * (m-i) % MOD * (n-1) % MOD * (y[i] - y[i-1]) % MOD * (x[1] - x[0]) % MOD;
    }
    ll res = ans;
    for(int i = 2; i < n; i++) {
        res = res * qpow(i-1, MOD - 2) % MOD * qpow(n-i+1, MOD-2) % MOD;
        res = res * i * (n-i) % MOD;
        res = res * qpow(x[i-1] - x[i-2], MOD-2) % MOD * (x[i] - x[i-1]) % MOD;
        up(ans, res);
    }
    cout << ans << endl;
    return 0;
}