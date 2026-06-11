#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,dp[1000005],mod=1e9+7,sum,ans;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    dp[n]=sum=n;
    for(ll i=n-1;i>0;i--){
      dp[i]=sum - dp[i+2] + ( (n-1)*(n-1))%mod + mod;
      dp[i]%=mod;
      dp[i]+=min(n-1,i+1);
      dp[i]%=mod;
      sum+=dp[i];
    }
    cout<<dp[1];
}