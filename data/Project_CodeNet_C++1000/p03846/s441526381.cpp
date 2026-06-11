#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

const int MAX_N = 1e5;
const int MOD = 1000000007;

int h[MAX_N];

ll mod_pow(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b & 1) return (a * mod_pow(a, b - 1, p)) % p;
    ll t = mod_pow(a, b / 2, p);
    return (t * t) % p;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        h[a]++;
    }
    ll ans = 0;
    if (n & 1) {
        if (h[0] != 1) {
            if (n != 1) {
                cout << 0 << endl;
                return 0;
            } else {
                cout << 1 << endl;
                return 0;
            }
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (i & 1) {
                if (h[i]) flag = false;
            } else {
                if (h[i] != 2) flag = false;
            }
        }
        if (flag) ans = mod_pow(2, n / 2, MOD);
        else {
            cout << 0 << endl;
            return 0;
        }
    } else {
        if (h[0]) {
            cout << 0 << endl;
            return 0;
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                if (h[i]) flag = false;
            } else {
                if (h[i] != 2) flag = false;
            }
        }
        if (flag) ans = mod_pow(2, n / 2, MOD);
        else {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}