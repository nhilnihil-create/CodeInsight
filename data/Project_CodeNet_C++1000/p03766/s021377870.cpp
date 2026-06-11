#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll dp[2555555]={0},rsum[2555555]={0};
const ll mod=1e9+7;
int main(){
  ll n;
  cin>>n;
  ll ans=0;
  dp[1]=1;
  rsum[1]=1;
  for(ll i=2;i<=2*n+1;i++){
    if(i<=n){
      ll v1=dp[i-1];
      ll v2=0;
      if(i-3>0){
        v2+=rsum[i-3];
        v2%=mod;
      }
      if(i-n-2>0){
        v2-=rsum[i-n-2];
        v2+=mod;
        v2%=mod;
      }
      dp[i]=(v1+v2)%mod;
      ans+=v2*(n-1);
      ans%=mod;
    //  cout<<i<<":"<<v1<<" "<<v2<<" "<<ans<<endl;
    }
    else if(i<=2*n){
      ll kans=0;
      ll L=max((ll)1,i-n-1),R=min(n-1,i-3);
      kans+=rsum[R];
      kans-=rsum[L-1];
      kans+=mod;
      kans%=mod;

      ans+=kans*n;
      ans%=mod;

      if(i-3>=n){
        ans+=dp[n];
        ans%=mod;
      }
      else if(i-1==n){
        ans+=dp[n];
        ans%=mod;
      }
  //    cout<<i<<":"<<kans<<" "<<ans<<endl;

    }
    else if(n>1){
      ans+=dp[n];
//      cout<<i<<":"<<dp[n]<<" "<<ans<<endl;
      ans%=mod;
    }
    rsum[i]=(rsum[i-1]+dp[i])%mod;
  }
  cout<<ans<<endl;
}
