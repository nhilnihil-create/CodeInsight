#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll h, w;
    cin >> h >> w;
    if(h % 3 == 0 || w % 3 == 0) cout << 0 << endl;
    else{
        ll ans = h * w;
        for(int i = 1; i < w; i++){
            ll a = i * h;
            ll b = (w - i) * (h / 2);
            ll c = (w - i) * ((h + 1) / 2);
            ll m = max({a, b, c}) - min({a, b, c});
            ans = min(ans, m);
        }
        for(int i = 1; i < h; i++){
            ll a = i * w;
            ll b = (h - i) * (w / 2);
            ll c = (h - i) * ((w + 1) / 2);
            ll m = max({a, b, c}) - min({a, b, c});
            ans = min(ans, m);
        }
        ans = min({ans, w, h});
        cout << ans << endl;
    }
    
}