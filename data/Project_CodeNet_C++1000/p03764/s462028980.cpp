#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int main(int argc, char const *argv[]) {
    int n,m;cin>>n>>m;
    vector<ll> x(n), y(m);
    rep(i,n) cin>>x[i];
    rep(i,m) cin>>y[i];

    ll X = 0; ll Y = 0;

    rep(i,n) {
        ll dec = x[i]*(n-1-i);
        ll inc = x[i]*i;
        X += (inc-dec);
        X%=MOD;
    }

    rep(i,m) {
        ll dec = y[i]*(m-1-i);
        ll inc = y[i]*i;
        Y += (inc-dec);
        Y%=MOD;
    }

    ll ans = X*Y%MOD;

    cout << ans << endl;

    return 0;
}
