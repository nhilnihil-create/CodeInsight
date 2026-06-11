#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll mod = 1000000007;

ll modpow(ll a, ll n, ll m) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}


int main() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    map<ll, ll> nmp;
    for (ll i = n - 1; i >= 0; i -= 2) {
        if (i == 0) nmp[i] = 1;
        else nmp[i] = 2;
    }
    if (mp != nmp) {
        cout << 0 << endl;
        return 0;
    }
    cout << modpow(2, n / 2, mod) << endl;
}
