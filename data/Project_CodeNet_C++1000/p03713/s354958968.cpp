#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    ll H, W;
    cin >> H >> W;

    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = H * W;
    rep(i, 2) {
        rep(g_w, W) {
            ll g = H * g_w;
            int w = W - g_w;
            int w_b = w / 2;
            int w_r = w - (w / 2);
            ll b = H * w_b;
            ll r = H * w_r;
            chmin(ans, abs(max(max(g, b), r) - min(min(g, b), r)));

            int h_b = H / 2;
            int h_r = H - h_b;
            b = h_b * (W - g_w);
            r = h_r * (W - g_w);
            chmin(ans, abs(max(max(g, b), r) - min(min(g, b), r)));
        }

        swap(H, W);
    }
    cout << ans << endl;
}