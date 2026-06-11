#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[55][55]={0},cnt[55][55]={0};
int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  cnt[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=b;j++) dp[i][j]-=1000000000000000000;
  }
  dp[0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=b;j++){
      dp[i+1][j]=dp[i][j];
      cnt[i+1][j]=cnt[i][j];
    }
    ll val;
    cin>>val;
    for(int j=0;j<b;j++){
      if(dp[i+1][j+1]<dp[i][j]+val){
        dp[i+1][j+1]=dp[i][j]+val;
        cnt[i+1][j+1]=cnt[i][j];
      }
      else if(dp[i+1][j+1]==dp[i][j]+val){
        cnt[i+1][j+1]+=cnt[i][j];
      }
    }
  }
  /*for(int i=0;i<n;i++){
    for(int j=0;j<=b;j++) cout<<dp[i][j]<<" ";
    cout<<endl;
  }*/
  ll max_v=dp[n][a],max_num=cnt[n][a];
  for(ll i=a;i<=b;i++){
    bool f=true;
    for(ll j=a;j<=b;j++){
      if(i==j) continue;
      if(dp[n][i]*j<dp[n][j]*i) {
        f=false;
        break;
      }
    }
    if(f){
      max_v=dp[n][i];
      max_num=i;
    }
  }
  cout<<fixed<<setprecision(10)<<(double)max_v/max_num<<endl;
  ll ans=0;
  for(int i=a;i<=b;i++){
    if(dp[n][max_num]*i==dp[n][i]*max_num) ans+=cnt[n][i];
  }
  cout<<ans<<endl;

}
