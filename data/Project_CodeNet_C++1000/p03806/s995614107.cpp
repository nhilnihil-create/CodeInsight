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

//dp[i][j]はそれぞれiグラム、jグラム買うときの最小価格
vector<vector<ll>> dp(500, vector<ll>(500, INF));

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll Ma;
    cin >> Ma;
    ll Mb;
    cin >> Mb;
    vector<ll> a(N,0);
    vector<ll> b(N,0);
    vector<ll> c(N,0);
    for(ll i=0;i<N;++i)cin>>a[i]>>b[i]>>c[i];
    dp[0][0]=0;
    //１つずつ商品を解禁
    for(ll i=0;i<N;++i){
        for(ll j=499;j>=a[i];--j){
            for(ll k=499;k>=b[i];--k){
                if(dp[j-a[i]][k-b[i]]==INF)continue;
                chmin(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
            }
        }
    }
    ll ans=INF;
    ll A=Ma,B=Mb;
    while(A<500&&B<500){
        chmin(ans,dp[A][B]);
        A+=Ma;B+=Mb;
    }
    if(ans==INF)prt(-1)
    else prt(ans)

    return 0;
}
