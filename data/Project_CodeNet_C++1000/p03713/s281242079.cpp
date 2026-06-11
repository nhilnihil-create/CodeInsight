
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll h, w;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
        exit(0);
    }
    // 12
    // 13
    ll ans = min(h, w);
    for (int i = 1; i < w; ++i) {
        ll left = i * h;
        ll right1 = (w - i) * (h / 2);
        ll right2 = (w - i) * ((h + 1) / 2);
        vector<ll> v = {left, right1, right2};
        sort(v.begin(), v.end());
        ans = min(ans, v[2] - v[0]);
    }
    for (int i = 1; i < h; ++i) {
        ll up = i * w;
        ll right1 = (h - i) * (w / 2);
        ll right2 = (h - i) * ((w + 1) / 2);
        vector<ll> v = {up, right1, right2};
        sort(v.begin(), v.end());
        ans = min(ans, v[2] - v[0]);
    }
    cout << ans << endl;

    return 0;
}

