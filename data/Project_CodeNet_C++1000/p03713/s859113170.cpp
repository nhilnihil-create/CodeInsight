#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll h, w; cin >> h >> w;

    ll ans = LINF;
    for (ll i = 1; i < h; ++i) {
        //縦に割る
        ll s[3] = {};
        s[0] = i * w;
        s[1] = (h - i) * (w / 2);
        s[2] = (h - i) * (w - w / 2);

        ll mx = 0;
        ll mn = LINF;
        for (ll k = 0; k < 3; ++k) {
            mx = max(mx, s[k]);
            mn = min(mn, s[k]);
        }

        ans = min(ans, mx - mn);

        //横に割る
        s[0] = i * w;
        s[1] = ((h - i) / 2) * w;
        s[2] = ((h - i) - (h - i) / 2) * w;

        mx = 0;
        mn = LINF;
        for (ll k = 0; k < 3; ++k) {
            mx = max(mx, s[k]);
            mn = min(mn, s[k]);
        }

        ans = min(ans, mx - mn);
    }

    swap(h, w);
    for (ll i = 1; i < h; ++i) {
        //縦に割る
        ll s[3] = {};
        s[0] = i * w;
        s[1] = (h - i) * (w / 2);
        s[2] = (h - i) * (w - w / 2);

        ll mx = 0;
        ll mn = LINF;
        for (ll k = 0; k < 3; ++k) {
            mx = max(mx, s[k]);
            mn = min(mn, s[k]);
        }

        ans = min(ans, mx - mn);

        //横に割る
        s[0] = i * w;
        s[1] = ((h - i) / 2) * w;
        s[2] = ((h - i) - (h - i) / 2) * w;

        mx = 0;
        mn = LINF;
        for (ll k = 0; k < 3; ++k) {
            mx = max(mx, s[k]);
            mn = min(mn, s[k]);
        }

        ans = min(ans, mx - mn);
    }

    cout << ans << endl;
}