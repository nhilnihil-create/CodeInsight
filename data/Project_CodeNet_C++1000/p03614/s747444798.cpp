#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    ll num = 0, p, s = 0;
    for ( int i = 1; i <= N; i++ ) {
        cin >> p;
        if ( s > 0 ) {
            s = 0;
            continue;
        }
        if ( p == i ) {
            num++;
            s++;
        }
    }
    return num;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}