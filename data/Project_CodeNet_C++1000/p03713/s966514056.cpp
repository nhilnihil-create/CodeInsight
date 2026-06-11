#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

const int INF = 1001001001;

int main() {
    ll h, w;
    cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = INF;
    for (ll i = 1; i < h; i++) {
        ll a = i * w;
        if ((h - i) % 2 == 0 || w % 2 == 0) ans = min(ans, abs(a - (h - i) * w / 2));
        else {
            ll b = (h - i) * (w / 2), c = (h - i) * w - b;
            ll maxs = max({ a, b, c }), mins = min({ a, b, c });
            ans = min(ans, maxs - mins);
            b = ((h - i) / 2) * w, c = (h - i) * w - b;
            maxs = max({ a, b, c }), mins = min({ a, b, c });
            ans = min(ans, maxs - mins);
        }
    }
    for (ll i = 1; i < w; i++) {
        ll a = i * h;
        if (h % 2 == 0 || (w - i) % 2 == 0) ans = min(ans, abs(a - h * (w - i) / 2));
        else {
            ll b = (h / 2) * (w - i), c = h * (w - i) - b;
            ll maxs = max({ a, b, c }), mins = min({ a, b, c });
            ans = min(ans, maxs - mins);
            b = h * ((w - i) / 2), c = h * (w - i) - b;
            maxs = max({ a, b, c }), mins = min({ a, b, c });
            ans = min(ans, maxs - mins);
        }
    }
    cout << ans << endl;
}