#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void pattern01 (ll &H, ll &W, ll &ans) {
    ll Smin, Smax;
    Smin = (H / 3) * W;
    if ((H - H / 3) % 2 == 0) Smax = ((H - H / 3) / 2) * W;
    else Smax = ((H - H / 3) / 2 + 1) * W;
    ans = min(ans, Smax-Smin);
}

void pattern02 (ll &H, ll &W, ll &ans) {
    if (H % 2 == 0) {
        for (int i = 1; i * 2 <= W + 1; ++i) {
            ll Smin = min(H/2*(W-i), H*i);
            ll Smax = max(H/2*(W-i), H*i);
            ans = min(ans, Smax-Smin);
        }
    } else {
        for (int i = 1; i * 2 <= W + 1; ++i) {
            ll Smin = min(H/2*(W-i), H*i);
            ll Smax = max((H/2+1)*(W-i), H*i);
            ans = min(ans, Smax-Smin);
        }
    }
}

int main() {
    ll H, W;
    cin >> H >> W;
    ll ans = 10e10;
    if (H > 2) pattern01(H, W, ans);
    if (W > 2) pattern01(W, H, ans);
    pattern02(H, W, ans);
    pattern02(W, H, ans);
    cout << ans << endl;
}

