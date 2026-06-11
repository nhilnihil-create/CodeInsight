#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, a;
    cin >> N;
    ll ans = 0, h = 0;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        if ( a < h+1 ) continue;
        if ( a == h+1 ) {
            h++;
            continue;
        }
        ans += (a-1) / (h+1);
        if ( h == 0 ) h++;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}