#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll H, W;
int main() {
    cin >> H >> W;

    ll ans = INF;

    // 縦分割
    if (H % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll pat1_max = ((H / 3) + 1) * W;
    ll pat1_min = ((H / 3)) * W;
    ll pat1_area = pat1_max - pat1_min;
    ans = min(ans, pat1_area);

    ll pat2_max = ((W / 3) + 1) * H;
    ll pat2_min = ((W / 3)) * H;
    ll pat2_area = pat2_max - pat2_min;
    ans = min(ans, pat2_area);


    // pat3 ( | 分割)
    ll w1 = (W / 2);
    ll w2 = ceil(W / 2.0);

    // h を動かす
    for (int h = 1; h <= H - 1; h++) {
        ll a1 = h * W;
        ll a2 = (H - h) * w1;
        ll a3 = (H - h) * w2;
        vector<ll> v1 = {a1, a2, a3};
        // cout << a1 << " " << a2 << " " << a3 << endl;
        sort(v1.begin(), v1.end());
        ll pat3_area = v1[2] - v1[0];
    
        ans = min(ans, pat3_area);
    }
    // cout << w1 << " " << w2 << endl;

    // pat4 ( - 分割)
    ll h1 = H / 2;
    ll h2 = ceil(H / 2.0);
    for (int w = 1; w <= W - 1; w++) {
        ll a1 = w * H;
        ll a2 = (W - w) * h1;
        ll a3 = (W - w) * h2;
        vector<ll> v1 = {a1, a2, a3};
        // cout << a1 << " " << a2 << " " << a3 << endl;
        sort(v1.begin(), v1.end());
        ll pat4_area = v1[2] - v1[0];
        ans = min(ans, pat4_area);
    }

    cout << ans << endl;
}