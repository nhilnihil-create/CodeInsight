#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n,ma,mb;cin >> n >>ma >>mb;
    vl a(n),b(n),c(n);
    rep(i,n)cin >> a[i] >>b[i] >>c[i];
    ll ans=INF;
    ll ia=ma,ib=mb;
    while(ma<=400&&mb<=400){
        ll dp[ma+1][mb+1];
        rep(j,ma+1)rep(k,mb+1)dp[j][k]=inf;
        dp[0][0]=0;
        rep(i,n){
            per(j,ma+1){
                per(k,mb+1){
                    if(j+a[i]<=ma&&k+b[i]<=mb){
                        chmin(dp[j+a[i]][k+b[i]],dp[j][k]+c[i]);
                    }
                }
            }
        }
        if(dp[ma][mb]!=inf){
            chmin(ans,dp[ma][mb]);
        }
        ma+=ia;
        mb+=ib;
    }
    if(ans!=INF)cout <<ans <<endl;
    else cout << -1 <<endl;
}