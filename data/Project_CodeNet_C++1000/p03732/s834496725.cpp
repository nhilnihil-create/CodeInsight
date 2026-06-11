#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

vvll dp(101, vll(100000, 0));

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, W;
    cin >> n >> W;
    vll weight(n), value(n);
    rep(i, n){
        cin >> weight[i] >> value[i];
    }
    map<ll, ll> mp;
    vll pm;
    rep(i, n+1)repr(j, i*weight[0], i*weight[0]+i*3+1){
        if(!mp.count(j)){
            mp.emplace(j, SZ(pm));
            pm.emplace_back(j);
        }
    }
    auto it = upper_bound(ALL(pm), W);
    ll x, y;
    if(it == pm.begin()){
        x = y = 0;
    }else{
        --it;
        x = *it;
        y = it-pm.begin();
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= y; ++j) {
            ll w = pm[j];
            if(w >= weight[i]){
                if(mp.count(w-weight[i])){
                    dp[i+1][j] = max(dp[i][mp[w-weight[i]]] + value[i], dp[i][j]);
                }else{
                    dp[i+1][j] = max(dp[i+1][j-1], dp[i][j]);
                }
            }
            else dp[i+1][j] = dp[i][j];
        }
    }
    dump(pm);
    dump(mp);
    dump(x);
    dump(y);
    rep(i, n+1) dump(i, dp[i]);
    cout << dp[n][y] << endl;
    return 0;
}