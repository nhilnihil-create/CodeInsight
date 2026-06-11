#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W;
    cin >> H >> W;

    ll ans = pow(10, 12);

    if(H >= 3LL) {
        if(H % 3LL) {
            ans = min(ans, W);
        } else {
            ans = 0;
        }
    }

    if(W >= 3LL) {
        if(W % 3LL) {
            ans = min(ans, H);
        } else {
            ans = 0;
        }
    }

    for(ll i = 1; i < H; i++) {
        ll a = i * W;
        ll b, c;
        if(W % 2LL) {
            b = (H - i) * (W / 2LL);
            c = (H - i) * (W / 2LL + 1LL);
        } else {
            b = (H - i) * (W / 2LL);
            c = (H - i) * (W / 2LL);
        }

        ll x = max(a, max(b, c));
        ll y = min(a, min(b, c));

        ans = min(ans, x - y);
    }

    for(ll i = 1; i < W; i++) {
        ll a = i * H;
        ll b, c;
        if(H % 2LL) {
            b = (W - i) * (H / 2LL);
            c = (W - i) * (H / 2LL + 1LL);
        } else {
            b = (W - i) * (H / 2LL);
            c = (W - i) * (H / 2LL);
        }

        ll x = max(a, max(b, c));
        ll y = min(a, min(b, c));

        ans = min(ans, x - y);
    }

    cout << ans << endl;
}