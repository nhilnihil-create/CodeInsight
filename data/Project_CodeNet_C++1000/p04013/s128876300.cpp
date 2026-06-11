#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

//dp[i][j]はi個使い和がjのもの
vector<vector<ll>> dp(51, vector<ll>(2501, 0));

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A;
    cin >> A;
    vector<ll> X(N,0);
    for(ll i=0;i<N;++i)cin>>X[i];

    dp[0][0]=1;

    //１つずつ解禁
    for(ll i=0;i<N;++i){
        for(ll j=50;j>=1;--j){
            for(ll k=2500;k>=X[i];--k){
                dp[j][k]+=dp[j-1][k-X[i]];
            }
        }
    }

    ll ans=0;

    for(ll i=1;i<=50;++i){
        ans+=dp[i][i*A];
    }

    prt(ans)

    
    return 0;
}
