#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll X;
    cin >> X;
    ll n = (sqrt(1+8*X) - 1) /2;
    while ( n * (n+1) /2 < X) n++;
    return n;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}