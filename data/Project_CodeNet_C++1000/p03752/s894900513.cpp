//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1e60;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    ll ans = INF;
    for(int bit = 0; bit < (1 << n); bit++) {
        vector<int> select;
        for(int i = 0; i < n; ++i) {
            if(bit & (1 << i)) {
                select.push_back(i);
            }
        }
        if((int)select.size()< k) continue;
        vector<ll> tmpa = a;
        ll tmpans = 0;
        for(auto v : select) {
            ll height = tmpa[v];
            ll maxheihgt = 0;
            for(int i = 0; i < v; i++) {
                maxheihgt = max(maxheihgt,tmpa[i]); 
            }
            if(maxheihgt >= height) {
                ll add = maxheihgt - height + 1;
                tmpa[v] += add;
                tmpans += add;
            }
        }
        ans = min(ans,tmpans);
    }
    cout << ans << endl;
    return 0;
}