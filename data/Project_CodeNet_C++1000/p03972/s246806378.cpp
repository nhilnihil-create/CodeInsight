#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int w, h;
    cin >> w >> h;
    vector<pair<ll, bool>> pqs;
    rep(i, w + h) {
        ll p;
        cin >> p;
        pqs.emplace_back(p, i < w);
    }
    int a = w + 1, b = h + 1;
    ll ans = 0;
    sort(pqs.begin(), pqs.end());
    rep(i,w+h){
        if(pqs[i].second){
            ans += b * pqs[i].first;
            a--;
        } else {
            ans += a * pqs[i].first;
            b--;
        }
    }
    cout << ans << endl;
}