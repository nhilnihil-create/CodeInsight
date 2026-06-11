#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;

int main() {
    ll n,A,B; cin >> n >> A >> B;
    vector<tuple<ll,ll,ll>> tp(n);
    rep(i,n){
        ll a,b,c; cin >> a >> b >> c;
        tp[i] = tie(a,b,c);
    }
    ll dp[n+1][405][405];
    rep(i,n+1) rep(j,401) rep(k,401) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    rep(i,n){
        ll a,b,c;
        tie(a,b,c) = tp[i];
        //cout << a << b << c << endl;
        rep(j,401){
            rep(k,401){
                dp[i+1][j][k] = dp[i][j][k];
                if(j - a >= 0 && k - b >= 0) dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j-a][k-b]+c);
            }
        }
    }
    ll ans = inf;
    REP(j,1,401){
        if(j%A==0) {
            if(j/A*B<=400) ans = min(ans, dp[n][j][j/A*B]);
        }
    }
    if(ans != inf) cout << ans << endl;
    else puts("-1");
}