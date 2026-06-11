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


int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll ans = 0;
    rep(i, n) {
        if (i==0) continue;
        ll c = a*(x[i]-x[i-1]);
        chmin(c, b);
        ans += c;
    }
    
    cout << ans << endl;
    return 0;
}
