#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t N;
int64_t dp[1000005];
int main(){
  cin>>N;
  dp[0]=1;dp[1]=1;
  int64_t sum=2;
  for(int i=2;i<=N;i++){
   dp[i]=(sum-dp[i-2]+mod)%mod;
    sum=(sum+dp[i])%mod;
  }int64_t ans=(dp[N]+dp[N-1]*(N-1))%mod;
  int64_t n=((N-1)*(N-1))%mod;
  for(int i=0;i<N-1;i++){
  ans=(ans+dp[i]*(n+i+1))%mod;
   }cout<<ans<<endl;
  return 0;
}