#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(){
    ll h, w;
    cin >> h >> w;

    ll ans = h * w;
    vector<ll> s(3, 0);
    rep(i, 2) {
        for (ll j=1;j<h;++j) {
            // 縦割り
            s[0] = j * w;
            s[1] = (h - j) * (w / 2);
            s[2] = h * w - (s[0] + s[1]);
            sort(all(s));
            ans = min(ans, s[2] - s[0]);

            // 横割り
            s[0] = j * w;
            s[1] = ((h - j) / 2) * w;
            s[2] = h * w - (s[0] + s[1]);
            sort(all(s));
            ans = min(ans, s[2] - s[0]);
        }
        swap(h, w);
    }

    cout << ans << endl;
}