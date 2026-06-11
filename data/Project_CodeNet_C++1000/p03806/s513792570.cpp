//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
ll dp[41][401][401];
int main(){
    rep(i,41){
        rep(j,401){
            rep(k,401)dp[i][j][k]=INF;
        }
    }
    dp[0][0][0]=0;
    ll n;cin>>n;
    ll ma,mb;cin>>ma>>mb;
    vl a(n),b(n),c(n);
    rep(i,n)cin>>a[i]>>b[i]>>c[i];
    rep(i,n){
        rep(j,401){
            rep(k,401){
                dp[i+1][j][k]=min(dp[i][j][k],dp[i+1][j][k]);
                if(j>=a[i]&&k>=b[i])dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
            }
        }
    }
    ll ans=INF;
    for(ll i=1;i*ma<=400&&i*mb<=400;i++){
        ans=min(ans,dp[n][i*ma][i*mb]);
    }
    if(ans>=INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
    