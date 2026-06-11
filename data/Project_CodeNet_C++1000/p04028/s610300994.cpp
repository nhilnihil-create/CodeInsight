#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll mod=1000000007;
ll N;string s;
ll dp[2][10010];
int main(){
  cin>>N>>s;
  ll M=s.size();
  dp[0][0]=1;
  for(int i=1;i<=N;i++){
    for(int j=0;j<=10005;j++)
      if(j==0){
      dp[1][0]=(dp[0][0]+2*dp[0][1])%mod;
      }else{
      dp[1][j]=(dp[0][j-1]+2*dp[0][j+1])%mod;
      } for(int j=0;j<=10005;j++)
          dp[0][j]=dp[1][j];
  }
    cout<<dp[1][M]<<endl;
  return 0;
}