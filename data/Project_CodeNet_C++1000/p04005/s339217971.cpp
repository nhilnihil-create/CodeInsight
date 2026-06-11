#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = a * b * c;
    if (x & 1) {
        ll n = x - (a - 1) * b * c;
        n = min(n, x - (b - 1) * c * a);
        n = min(n, x - (c - 1) * a * b);
        cout << n << endl;
    } else {
        cout << 0 << endl;
    }
}
