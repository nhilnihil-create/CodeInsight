#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, h;
    cin >> w >> h;
    vector<P> d;
    rep(i, 0, w){
        int p; cin >> p;
        d.push_back(P(p, 0));
    }
    rep(i, 0, h){
        int q; cin >> q;
        d.push_back(P(q, 1));
    }
    sort(all(d));
    int nh = h + 1, nw = w + 1, ans = 0;
    rep(i, 0, d.size()){
        if(d[i].second == 0){
            // cout << " " << d[i].first << " " << nh << " " << nw << endl;
            ans += d[i].first * nh; nw--;
        }else{
            // cout << d[i].first << " " << nh << " " << nw << endl;            
            ans += d[i].first * nw; nh--;
        }
    }
    cout << ans << endl;
}