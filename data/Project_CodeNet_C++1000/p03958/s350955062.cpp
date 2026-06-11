#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll K, T, a, m = 0;
    cin >> K >> T;
    for ( int i = 0; i < T; i++ ) {
        cin >> a;
        m = max(m, a);
    }
    ll ans = m - 1 - (K - m);
    if ( ans < 0 ) ans = 0;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}