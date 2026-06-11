#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll combination(ll n, ll r) {
    if (n / 2 <= r) {
        r = n - r;
    }

    ll res = 1;
    for (ll i = 0; i < r; ++i) {
        res *= (n - i);
    }
    for (ll i = r; i > 0; --i) {
        res /= i;
    }

    return res;
}

int main() {

    ll n, p; cin >> n >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll even = 0;
    ll odd = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }

    //奇数
    ll sum = 0;
    for (ll i = 1; i <= odd; i += 2) {
        ll com = combination(odd, i);
        com *= (ll)pow(2, even);
        sum += com;
    }

    if (p == 1) {
        cout << sum << endl;
    } else {
        cout << (ll)pow(2, n) - sum << endl;
    }
}