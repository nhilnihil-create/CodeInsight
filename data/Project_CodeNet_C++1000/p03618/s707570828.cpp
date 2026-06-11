#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string A;
    cin >> A;
    ll c = 0;
    map<char, int> m;
    for ( char a : A ) {
        m[a]++;
        c += m[a]-1;
    }
    ll ans = A.size() * (A.size() - 1) / 2 + 1 - c;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}