#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    ll H, W; cin >> H >> W;
    if (H%3 == 0 || W%3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll a, b, c;
    ll ans = min(H, W);
    for (ll i = 1; i < H; i++) {
        a = i*W;
        b = (H-i)*(W/2);
        c = (H-i)*W - b;
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    for (ll i = 1; i < W; i++) {
        a = i*H;
        b = (W-i)*(H/2);
        c = (W-i)*H - b;
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    
    cout << ans << endl;
}
