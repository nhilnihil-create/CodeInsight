#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;

ll rep_pow(int n, int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll t = rep_pow(n, p / 2);
        return t * t % MOD;
    } else {
        return n * rep_pow(n, p - 1) % MOD;
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> t(n), a(n);
    int ti = 0;
    int ai = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (t[i] > t[i - 1]) {
            ti = i;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            ai = i;
        }
    }
    if (a[ai] != t[ti] || ai < ti) {
        cout << 0;
        return 0;
    }
    vector<ll> mins(n);
    for (int i = 0; i < n; i++) {
        mins[i] = min(a[i], t[i]);
    }
    ll cur = 0;
    ll ans = 1;
    for (int i = 0; i <= ti; i++) {
        if (cur < mins[i]) {
            cur = mins[i];
        } else {
            ans *= cur % MOD;
            ans %= MOD;
        }
    }
    cur = 0;
    for (int i = n - 1; i >= ai; i--) {
        if (cur < mins[i]) {
            cur = mins[i];
        } else {
            ans *= cur % MOD;
            ans %= MOD;
        }
    }
    if (ai - ti >= 2) {
        ans *= rep_pow(a[0], ai - ti - 1) % MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
