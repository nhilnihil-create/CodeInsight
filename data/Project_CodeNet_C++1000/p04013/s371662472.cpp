#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll count(ll arr[], ll n,ll S){
  ll dp[n+1][n*S+1][n+1]={0};
  
  for(int i=n;i>=0;i--){
    for(int j=0;j<=n*S;j++){
      for(int k=0;k<=n;k++){
        if(i==n){
          if(j==0&&k==0){
              dp[i][j][k]=1;
          }
        }
        else{
          if(j-arr[i]>=0&&k>0){
            dp[i][j][k]=dp[i+1][j][k]+dp[i+1][j-arr[i]][k-1];
          }else{
            dp[i][j][k]=dp[i+1][j][k];
          }
        }
      }
    }
  }
  ll ans=0;
  for(int i=1;i<=n;i=i+1){
    ans+=dp[0][S*i][i];
  }
  return ans;
}

int main(){
  ll n,A;
  cin>>n>>A;
  ll arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<count(arr,n,A);
  return 0;
}