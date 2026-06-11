#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    ll ans = 0, m = 0, a, b;
    for ( int i = 0; i < N; i++ ) {
        cin >> a >> b;
        if ( m < a ) {
            m = a;
            ans = a + b;
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}