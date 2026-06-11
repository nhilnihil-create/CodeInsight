#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll pow(ll a, ll b, ll m) {
    ll res = 1;
    for (a %= m; b; b >>= 1, (a *= a) %= m)
        if (b & 1) (res *= a) %= m;
    return res;
}
ll n, m, a, b, ans, f[200005];
ll inv(ll x) {
    return pow(x, mod - 2, mod);
}
ll C(ll n, ll k) {
    return f[n] * inv(f[n-k]) % mod * inv(f[k]) % mod;
}
ll calc(ll n, ll m) {
    return C(n + m, m);
}
int main() {
    cin >> n >> m >> a >> b; f[0] = 1;
    for (ll i = 1; i <= n + m - 2; ++i)
        f[i] = f[i-1] * i % mod;
    for (ll i = b + 1; i <= m; ++i) {
        (ans += calc(n - a - 1, i - 1) % mod * calc(a - 1, m - i)) %= mod;
    }
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}