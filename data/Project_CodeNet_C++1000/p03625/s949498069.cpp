#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll n; cin >> n;
    map<ll, ll> mp;
    rep(i, n) {
        ll a; cin >> a;
        mp[a]++;
    }
    vector<ll> vc;
    for (auto it=mp.begin();it!=mp.end();it++) {
        if(it->second >= 2) {
            rep(i, it->second/2)
            vc.push_back(it->first);
        }
    }
    sort(vc.begin(), vc.end());
    ll m = vc.size();
    if(m < 2) cout << 0;
    else cout << vc[m-1] * vc[m-2];
}
