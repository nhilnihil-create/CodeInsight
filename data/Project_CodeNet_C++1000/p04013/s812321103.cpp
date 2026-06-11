#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t N,A;
  cin>>N>>A;
  vector<int64_t>X(N);
  for(int64_t i=0;i<N;i++){
  int64_t x; cin>>x;
    x-=A;
    X.at(i)=x;
  }vector<vector<int64_t>>dp(N+1,vector<int64_t>(5001,0));
  dp[0][2500]=1;
  for(int64_t i=1;i<=N;i++){
    for(int64_t j=2500-50*i; j<=2500+50*i;j++)
      dp[i][j]=dp[i-1][j]+dp[i-1][j-X.at(i-1)];
  }cout<<dp[N][2500]-1<<endl;
   return 0;
}
