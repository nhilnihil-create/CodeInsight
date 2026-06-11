#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    cout << "50\n";
    vector<ll> a(50, k / 50 + 49);
    for (int i = 0; i < 50; i++) {
        if (i >= k % 50) {
            a[i] -= k % 50;
        } else {
            a[i] += 51 - k % 50;
        }
    }
    for (ll i : a) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
