#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;

int main(){
  ll n;cin>>n;
  int mod=1000000007;
  ll dp[n+1];
  dp[0]=1;
  dp[1]=n;
  dp[2]=n*n %mod;
  rep(i,n-2){
    dp[i+3]=(2*dp[i+2]-dp[i+1]+dp[i]-1)%mod;
    if(dp[i+3]<0)dp[i+3]+=mod;
    }
  cout<<dp[n]<<endl;
  return 0;
  }

  
    
