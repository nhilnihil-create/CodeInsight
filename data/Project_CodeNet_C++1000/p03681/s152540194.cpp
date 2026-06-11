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

ll f(ll x) {
    if (x==0) return 1;
    ll res = 1;
    rep(i, x) {
        res *= (ll)(i+1);
        res %= mod;
    }
    return res;
}


int main(){
    ll n, m;
    cin >> n >> m;
    if (abs(n-m)>1) {
        cout << 0 << endl;
        return 0;
    }
    if (n==m) {
        ll ans = 1;
        rep(i, 2) {
            ans *= f(n);
            ans %= mod;
        }
        ans *= 2;
        ans %= mod;
        cout << ans << endl;
        return 0;
    }
    ll ans = 1;
    ans *= f(n);
    ans %= mod;
    ans *= f(m);
    ans %= mod;
    
    cout << ans << endl;
    return 0;
}
