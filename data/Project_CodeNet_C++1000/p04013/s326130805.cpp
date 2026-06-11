#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;

int main(){
  int n,a;ll ans=0;
  ll dp[51][51][2501];
  cin>>n>>a;
  vector<int> x(n,0);
  REP(i,n) cin>>x.at(i);
  REP(k,n*a+1){
    REP(i,n+1){
      REP(j,n+1){
        if(k==0){
          if(j==0||i==0) dp[i][j][k]=1;
          else dp[i][j][k]=0;
        }else{
          if(j==0||i==0) dp[i][j][k]=0;
          else{
            if(i<j) dp[i][j][k]=0;
            else if(k<x.at(i-1)) dp[i][j][k]=dp[i-1][j][k];
            else dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x.at(i-1)];
          }
        }
      }
    }
  }

  for(int i=1;i<=n;i++) ans+=(ll)(dp[n][i][i*a]);
  cout<<ans<<endl;
}