#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> H(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> H[i];
    }

    auto check = [&](ll n) {
        ll r = n;
        ll d = A - B;
        for ( int i = 0; i < N; i++ ) {
            ll h = H[i] - B * n;
            if ( h > 0 ) {
                r -= (h + d - 1) / d;
                if ( r < 0 ) return false;
            }
        }
        return true;
    };

    ll l = 0, r = 2 + 1e9 / B;
    while ( r - l > 1 ) {
        ll m = (l + r) / 2;
        if ( check(m) ) r = m;
        else l = m;
    }

    return r;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}