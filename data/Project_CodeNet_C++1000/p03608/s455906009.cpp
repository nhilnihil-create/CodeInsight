#include <bits/stdc++.h>
using namespace std;

const int64_t INF=10e9;

int main(){
  int N,M,R;
  cin>>N>>M>>R;
  vector<vector<int64_t>> dp(N,vector<int64_t>(N,INF));
  vector<int> r(R);

  for(int i=0;i<R;++i){
    cin>>r[i];
    --r[i];
  }

  for(int i=0;i<M;++i){
    int A,B;
    int64_t C;
    cin>>A>>B>>C;
    --A,--B;
    dp[A][B]=C,dp[B][A]=C;
  }

  for(int i=0;i<N;++i) dp[i][i]=0;

  for(int k=0;k<N;++k){
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }

  vector<int> d;
  for(int i=0;i<R;++i) d.push_back(i);
  int64_t ans=INF;
  do{
    int64_t subans=0;
    for(int i=0;i<R-1;++i) subans += dp[r[d[i]]][r[d[i+1]]];
    ans=min(ans,subans);
  }while(next_permutation(d.begin(),d.end()));

  cout<<ans<<endl;
}