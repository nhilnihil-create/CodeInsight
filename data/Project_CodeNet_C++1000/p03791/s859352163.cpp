#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, x, a = 1, b = 1;
    cin >> N;
    const ll MOD = 1e9 + 7;
    for ( ll i = 0; i < N; i++ ) {
        cin >> x;
        a = a * b % MOD;
        if ( x >= 2 * b - 1 ) b++;
    }
    return a;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}