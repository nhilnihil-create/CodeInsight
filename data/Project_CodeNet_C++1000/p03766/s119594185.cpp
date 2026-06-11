#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int dp[1111111],su[1111111];

signed main(){
  int n;
  cin>>n;
  dp[0]=1;dp[1]=n;
  su[0]=1;su[1]=n+1;
  for(int i=2;i<=n;i++){
    dp[i]=(dp[i-1]+(i>=3?su[i-3]:0LL)+(n-1)*(n-1)+(n-i+1))%MOD;
    su[i]=(su[i-1]+dp[i])%MOD;
    //cout<<dp[i]<<endl;
  }
  cout<<dp[n]<<endl;
  return 0;
}
