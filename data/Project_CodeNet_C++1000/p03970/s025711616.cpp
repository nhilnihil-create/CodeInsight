#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S, e = "CODEFESTIVAL2016";
    cin >> S;
    ll ans = 0;
    for ( int i = 0; i < S.size(); i++ ) {
        if ( S[i] != e[i] ) ans++;
    }

    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}