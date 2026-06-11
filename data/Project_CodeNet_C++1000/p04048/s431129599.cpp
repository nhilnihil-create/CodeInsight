#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, X;
    cin >> N >> X;
    ll ans = 0, a, b;
    ans += X;
    a = N, b = N - X;
    while ( b > 0 ) {
        ans += ( 1 + (a - b) / b * 2) * b + a % b;
        if ( a % b == 0 ) ans -= b;
        ll t = a % b;
        a = b;
        b = t;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}