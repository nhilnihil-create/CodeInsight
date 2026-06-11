#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+1);
    for ( int i = 1; i <= N; i++ ) {
        cin >> A[i];
    }
    vector<ll> b(N+1), c(N+1);
    for ( int i = 1; i <= N; i++ ) {
        b[i] = b[i-1] + (A[i] > 0 ? A[i] : 0);
        c[i] = c[i-1] + A[i];
    }
    ll ans = 0;
    for ( int i = 1; i <= N-K+1; i++ ) {
        ll s = c[i+K-1] - c[i-1];
        if ( s < 0 ) s = 0;
        s += b[i-1];
        s += b[N] - b[i+K-1];
        ans = max(ans, s);
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}