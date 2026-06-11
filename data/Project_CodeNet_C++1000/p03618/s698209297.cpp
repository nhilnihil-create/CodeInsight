#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//---------------------------------------------------------------------------------------------------
ll MOD = 1000000007;
ll f[201010], rf[201010];
ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    for(int i = 1; i < 201010; i++) f[i] = (f[i - 1] * i) % MOD;
    for(int i = 0; i < 201010; i++) rf[i] = inv(f[i]);
}
ll C(int n, int k) {
    if(n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * bc) % MOD;
}
//---------------------------------------------------------------------------------------------------

int main()
{
    init();
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> c(26);
    for(int i = 0; i < n; i++)
    {
        c[s[i]-'a']++;
    }
    ll ans = n * (n-1) / 2 + 1;
    for(int i = 0; i < 26; i++)
    {
        if(c[i] > 1) ans -= c[i] * (c[i]-1) / 2;
    }
    cout << ans << endl;
}
