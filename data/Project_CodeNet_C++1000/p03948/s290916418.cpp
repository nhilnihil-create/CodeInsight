#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, T;
    cin >> N >> T;
    ll a;
    ll amin = 1e9+1, tmax = 0, tnum = 0;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        ll t = a - amin;
        if ( tmax < t ) {
            tmax = t;
            tnum = 1;
        } else if ( tmax == t ) {
            tnum++;
        }
        if ( amin > a ) amin = a;
    }
    return tnum;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}