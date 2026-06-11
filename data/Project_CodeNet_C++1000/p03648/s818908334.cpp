#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll K;
    cin >> K;
    ll n = 50, r = K % n;
    vector<ll> a(n);
    for ( int i = 0; i < n; i++ ) {
        a[i] = n - 1 + K / n;
    }
    for ( int i = 0; i < n; i++ ) {
        if ( i < r ) {
            a[i] += n - r + 1;
        } else {
            a[i] += -r;
        }
    }
    cout << n << "\n";
    for ( int i = 0; i < n; i++ ) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

int main() {
    solve();
    return 0;
}