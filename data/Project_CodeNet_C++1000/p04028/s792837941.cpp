#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const int mod=1000000007;

ll pow(ll n,ll k){
  if(k<0)k+=mod-1;
  ll ret=1;
  while(k>0){
    if(k&1)ret=ret*n %mod;
    n=n*n %mod;
    k>>=1;
    }
  return ret;
  }

int main(){
  ll n;cin>>n;
  string s;cin>>s;
  ll m=s.size();
  ll dp[5010][5010];
  dp[0][0]=1;
  rep(i,n+1){
    rep(j,n-1)dp[i+1][j+1]=(2*dp[i][j]+dp[i][j+2])%mod;
    dp[i+1][0]=(dp[i][1]+dp[i][0])%mod;
    dp[i+1][n]=2*dp[i][n-1]%mod;
    }
  ll ans=dp[n][m]*pow(2,-m) %mod;
  cout<<ans<<endl;
  return 0;
  }