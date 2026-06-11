#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

ll f(ll x) {
    ll res = 0;
    while (x>0) {
        x /= 10;
        res++;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 1000;
    for (ll i=1; i*i<=n; i++) {
        if (n%i!=0) continue;
        ll j = n/i;
        ll res = max(f(i), f(j));
        chmin(ans, res);
    }
    
    
    cout << ans << endl;
    return 0;
}
