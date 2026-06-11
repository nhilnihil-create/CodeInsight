#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n,ww;
vector<map<ll,ll>> dp;
vector<Vi> d;
Vi w,v;


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n>>ww;
    w.resize(n);
    v.resize(n);
    dp.resize(n);
    d.resize(n);
    rep(i,n){
        cin>>w[i]>>v[i];
    }
    dp[0][w[0]]+=v[0];
    dp[0][0]=0;
    d[0].pb(0);
    d[0].pb(w[0]);
    rep(i,n){
        if(i==n-1)continue;
        rep(j,d[i].size()){
            if(d[i][j] == 0 && d[i+1].empty())d[i+1].pb(0);
            if(dp[i+1].count( d[i][j] + w[i+1] ) == 0)d[i+1].pb(d[i][j]+w[i+1]);
            if(d[i][j] != 0)if(dp[i+1].count( d[i][j]  ) == 0)d[i+1].pb(d[i][j]);
            ll tmp = dp[i+1][d[i][j] + w[i+1] ];
            chmax(tmp,dp[i][d[i][j]] + v[i+1] );
            dp[i+1][d[i][j]+w[i+1]] = tmp;
            tmp = dp[i+1][d[i][j]];
            chmax(tmp,dp[i][d[i][j]]);
            dp[i+1][d[i][j]] = tmp;
        }
    }
    ll ans = 0;
    rep(i,d[n-1].size()){
        ll tmp = dp[n-1][d[n-1][i]];
        if(d[n-1][i] <= ww)chmax(ans,tmp);
    }
    print(ans);
    return 0;
}