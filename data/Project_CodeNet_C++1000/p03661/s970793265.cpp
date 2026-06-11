#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> ca(N+1);
    ll a;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        ca[i+1] = ca[i] + a;
    }
    ll ans = 1e18;
    for ( int i = 1; i < N; i++ ) {
        ll x = abs(ca[i] - (ca[N] - ca[i]));
        if ( ans > x ) ans = x;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}