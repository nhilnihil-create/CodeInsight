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
//const ll MOD=1000000007LL;
const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

ll dp[2010][2010];
int main(){
  ll n,x;cin>>n>>x;
  vl a(n);
  rep(i,n)cin>>a[i];
  vvl data(n,vl (n));
  rep(j,n){
    ll MIN=INF;
    rep(i,n){
      
      MIN=min(MIN,a[(i+j)%n]);
      data[i][j]=MIN;
    }
  }
  rep(i,2010){
    rep(j,2010)dp[i][j]=INF;
  }
  dp[0][0]=0;
  rep(j,n){
    ll MIN=INF;    
    rep(i,n){
      MIN=min(dp[i][j],MIN);
      if(i!=0)dp[i][j+1]=min(MIN+data[i][j],dp[i-1][j+1]);
      else dp[i][j+1]=MIN+data[i][j];
    }
  }
  /*rep(i,n){
    rep(j,n+1)cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  rep(i,n){
    rep(j,n)cout<<data[i][j]<<" ";
    cout<<endl;
  }*/
  ll ans=INF;
  rep(i,n)ans=min(ans,dp[i][n]+i*x);
  cout<<ans<<endl;
}