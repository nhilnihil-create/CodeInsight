#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    ll x, y;
    cin >> x >> y;
    ll ans;
    if (x > y) {
        if (x < 0)
            ans = 2 + abs (x - y);
        else {
            ans = min (1 + abs (y + x), 2 + abs (y - x));
        }
    }
    else {
        ans = y - x;
        if (x <= 0 && y >= 0)
            ans = min (ans, 1 + abs (x + y));
    }
    cout << ans << "\n";
    return 0;
}
