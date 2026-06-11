#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n >> m;
    map<ll, ll> mp, mp2;
    ll ret = 0;
    vector<ll> v(n);
    for(i = 0; i < n; i++) {
        ll x;
        cin >> v[i];
        x = v[i];
        mp2[x]++;
        x %= m;
        mp[x]++;
    }
    for(i = 0; i < m; i++) {
        if(i == 0 || 2 * i == m) {
            ret += mp[i] / 2;
            mp[i] -= mp[i] / 2 * 2;
        } else {
            ll p = min(mp[i], mp[(m - i) % m]);
            ret += min(mp[i], mp[(m - i) % m]);
            mp[i] -= p;
            mp[(m - i) % m] -= p;
        }
    }
    for(i = 0; i < n; i++) {
        if(mp[v[i] % m] >= 2 && mp2[v[i]] >= 2) {
            ret += min(mp2[v[i]], mp[v[i] % m]) / 2;
            mp[v[i] % m] -= min(mp2[v[i]], mp[v[i] % m]) / 2 * 2;
            mp2[v[i]] = 0;
        }
    }
    cout << ret << endl;
    return 0;
}