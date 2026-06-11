#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll X, Y;
    cin >> X >> Y;
    return abs(X-Y) > 1;
}

int main() {
    string ans = solve() ? "Alice" : "Brown";
    cout << ans << "\n";
    return 0;
}