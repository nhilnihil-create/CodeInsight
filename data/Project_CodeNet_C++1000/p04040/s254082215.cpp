//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const ll mod = 1e9 + 7;

ll fact[N], inv[N];

ll Pow(ll a, ll b){
    ll res = 1;
    for (; b; b = b >> 1)
        res = res * (b & 1 ? a : 1) % mod, a = a * a % mod;
    return res;
}

ll C(ll n, ll m){
    if (m < 0 || n < m)
        return 0;
    return fact[n] * inv[m] % mod * inv[n - m] % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    fact[0] = inv[0] = 1;
    for (ll i = 1; i < N; i ++)
        fact[i] = fact[i - 1] * i % mod, inv[i] = Pow(fact[i], mod - 2);
    ll ans = C(h + w - 2, h - 1);
    for (ll i = 1; i <= b; i ++)
        ans = (ans - C(w - i + a - 1, a - 1) * C(h - a + i - 2, i - 1) % mod) % mod;
    ans = (ans + mod) % mod;
    cout << ans;
    return 0;
}
