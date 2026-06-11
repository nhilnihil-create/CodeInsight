//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,a;cin>>n>>a;
  ll dp[60][60][2510];
  dp[0][0][0]=1;
  for(ll k=1;k<=n;k++){
    ll x;cin>>x;
    rep(i,n+1){
      rep(j,n*a+1){
        if(i==0||j<x){
          dp[k][i][j]=dp[k-1][i][j];
          continue;
        }
        dp[k][i][j]=dp[k-1][i][j]+dp[k-1][i-1][j-x];
      }
    }
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    ans+=dp[n][i][i*a];
  }
  cout<<ans<<endl;
}
    
