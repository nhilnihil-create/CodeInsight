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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = INF;
    rep(_, 2) {
        ll sum = 0;
        ll res = 0;
        rep(i, n) {
            if (i%2==0) {
                ll x = 1LL - (sum+a[i]);
                chmax(x, 0LL);
                res += x;
                sum += (a[i]+x);
            }
            else {
                ll x = (sum+a[i]) + 1LL;
                chmax(x, 0LL);
                res += x;
                sum += (a[i]-x);
            }
        }
        chmin(ans, res);
        if (_==1) break;
        rep(i, n) {
            a[i] *= -1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
