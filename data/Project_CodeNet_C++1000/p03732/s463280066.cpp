#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int main() {
    ll N, W; cin >> N >> W;
    ll ans = 0;
    map<ll, ll> mp;
    rep(i, N) {
        ll w, v; cin >> w >> v;
        vector<P> pp;//post-processing
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            ll ww = it->first;
            ll vv = it->second;
            if(ww+w<=W&&mp[ww+w]<vv+v) {
                //mp[ww+w] = vv + v;
                pp.emplace_back(ww+w, vv+v);
                ans = max(ans, vv+v);
            }
        }
        rep(j, pp.size()) {
            mp[pp[j].first] = pp[j].second;
        }
        if(v > mp[w] && w <= W) {
            mp[w] = v;
            ans = max(ans, v);
        }
    }
    cout << ans;
}
