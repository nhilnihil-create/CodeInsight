#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

// aのn乗
ll modpow(ll a, ll n){
  ll r = 1;
  while (n) {
    r = r * ( (n%2)?a:1 ) %MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return r;
}

ll dp[5050][5050];

int main(){
  int N; cin>>N;
  string S; cin>>S;
  int m=S.length();
  dp[0][0]=1;
  rep(i,N) rep(j,N) if(dp[i][j]){
    (dp[i+1][j+1]+=2*dp[i][j])%=MOD;
    if(j) (dp[i+1][j-1]+=dp[i][j])%=MOD;
    else (dp[i+1][j]+=dp[i][j])%=MOD;
  }
  ll x=1;
  rep(i,m) (x*=2)%=MOD;
  (dp[N][m]*=modpow(x,MOD-2))%=MOD;
  cout<<dp[N][m]<<endl;
  return 0;
}
