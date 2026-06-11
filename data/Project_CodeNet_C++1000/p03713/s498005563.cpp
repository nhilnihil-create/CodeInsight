#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 1E+18;


int main(){
    ll h, w;
    cin >> h >> w;
    ll ans = INF;
    rep(i, h) {
        ll ih = h - i;
        ll iw = w;
        vector<ll> v;
        v.push_back(w*i);
        if (ih%2==0 || iw%2==0) {
            v.push_back(ih*iw/2);
        }
        else {
            ll x = min(ih, iw);
            v.push_back((ih*iw-x)/2);
            v.push_back((ih*iw+x)/2);
        }
        sort(whole(v));
        ll res = v.back() - v[0];
        chmin(ans, res);        
    }
    swap(h, w);
    rep(i, h) {
        ll ih = h - i;
        ll iw = w;
        vector<ll> v;
        v.push_back(w*i);
        if (ih%2==0 || iw%2==0) {
            v.push_back(ih*iw/2);
        }
        else {
            ll x = min(ih, iw);
            v.push_back((ih*iw-x)/2);
            v.push_back((ih*iw+x)/2);
        }
        sort(whole(v));
        ll res = v.back() - v[0];
        chmin(ans, res);        
    }
    
    cout << ans << endl;
    return 0;
}
