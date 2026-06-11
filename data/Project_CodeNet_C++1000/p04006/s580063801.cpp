#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int64_t x;
  cin>>x;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  vector<vector<int64_t>> dp(N,vector<int64_t>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int64_t K=(i+N-j)%N;
      dp[i][K]=p[j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=1;j<N;j++){
      dp[i][j]=min(dp[i][j],dp[i][j-1]);
    }
  }
  int64_t Z=167167167167167167;
  for(int64_t i=0;i<N;i++){
    int64_t A=0;
    for(int j=0;j<N;j++){
      A+=dp[j][i];
    }
    Z=min(Z,A+i*x);
  }
  cout<<Z<<endl;
}