#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    ll ans = LLINF;
    for(int h = 1; h < H; ++h) {
        ll s1 = (ll)h * W, s2 = (ll)(H - h) * (W / 2),
           s3 = (ll)(H - h) * W - s2;
        ll mi = min(s1, min(s2, s3)), ma = max(s1, max(s2, s3));
        ans = min(ans, ma - mi);
        s2 = (ll)(H - h) / 2 * W, s3 = (ll)(H - h) * W - s2;
        mi = min(s1, min(s2, s3)), ma = max(s1, max(s2, s3));
        ans = min(ans, ma - mi);
    }
    for(int w = 1; w < W; ++w) {
        ll s1 = (ll)w * H, s2 = (ll)(W - w) * (H / 2),
           s3 = (ll)(W - w) * H - s2;
        ll mi = min(s1, min(s2, s3)), ma = max(s1, max(s2, s3));
        ans = min(ans, ma - mi);
        s2 = (ll)(W - w) / 2 * H, s3 = (ll)(W - w) * H - s2;
        mi = min(s1, min(s2, s3)), ma = max(s1, max(s2, s3));
        ans = min(ans, ma - mi);
    }
    cout << ans << endl;
    return 0;
}
