#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    ll h,w; cin >> h >> w;
    ll ans;
    if (h%3 == 0 | w%3 == 0)  ans = 0;
    else ans = min(h,w);

    ll h2 = h/2;
    for (ll i = 1; i < w ; i ++ ) {
        vector<ll> S = {h2 * i, (h - h2) * i, h * (w - i)};
        sort(S.begin(),S.end());
        ans = min(ans, S[2] - S[0]);
    }

    ll w2 = w/2;
    for (ll i = 1; i < h ; i ++) {
        vector<ll> S = {w2 * i, (w - w2) * i, w * (h - i)};
        sort(S.begin(),S.end());
        ans = min(ans,S[2] - S[0]);
    }

    cout << ans << endl;
}