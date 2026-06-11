#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf = 1e18;
int main() {
    ll h, w; cin >> h >> w;
    ll ans = inf;
    if(h%3==0 || w%3==0) {
        ans = 0;
    } else {
        // fix H
        for(int i=1;i<w;i++) {
            vector<ll> vc;
            vc.push_back(h * i);
            vc.push_back((w-i) * (h/2));
            vc.push_back((w-i) * (h-h/2));
            sort(vc.begin(), vc.end());
            ans = min(ans, vc[2] - vc[0]);
        }

        // fix W
        for(int i=1;i<h;i++) {
            vector<ll> vc;
            vc.push_back(w * i);
            vc.push_back((h-i) * (w/2));
            vc.push_back((h-i) * (w-w/2));
            sort(vc.begin(), vc.end());
            ans = min(ans, vc[2] - vc[0]);
        }
        ans = min(ans, w);
        ans = min(ans, h);
    }
    cout << ans;
}
