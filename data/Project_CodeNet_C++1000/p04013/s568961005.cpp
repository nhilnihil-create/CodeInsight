#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,c,ans = 0,i,j,k;scanf("%lld%lld",&n,&a);
  ll dp[n+1][2501] = {};dp[0][0] = 1;
  for(i=0;i<n;i++){
    scanf("%lld",&c);
    for(k=n-1;k>=0;k--){
      for(j=0;j+c<=2500;j++) dp[k+1][j+c] += dp[k][j];
    }
  }
  for(i=1;i<=n;i++) ans += dp[i][a*i];
  printf("%lld\n",ans);
}