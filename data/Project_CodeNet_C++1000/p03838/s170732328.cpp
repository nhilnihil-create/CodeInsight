#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    ll x, y;
    cin >> x >> y;
    ll ans = INF;
    if (y >= x) {
        ans = min(ans, y - x);
    }
    if (y >= x * (-1)) {
        ans = min(ans, y + x + 1);
    }
    if (y * (-1) >= x) {
        ans = min(ans, -y - x + 1);
    }
    if (y * (-1) >= x * (-1)) {
        ans = min(ans, -y + x + 2);
    }
    cout << ans << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}