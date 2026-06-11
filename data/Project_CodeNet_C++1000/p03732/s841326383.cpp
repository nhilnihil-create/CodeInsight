#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, W;
  cin >> N >> W;
  int64_t vec[N][2];
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin >> vec[i][j];
    }
  }
  
  const int64_t W_MAX = 3*N+1;
  const int64_t W_START = vec[0][0];
  
  int64_t dp[N][W_MAX][N+1];
  for(int i=0; i<N; i++){
    for(int j=0; j<W_MAX; j++){
      for(int k=0; k<N+1; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  
  for(int i=0; i<N; i++){
    int64_t x = vec[i][0] - W_START;
    int64_t y = vec[i][1];
    if(i == 0){
      dp[i][x][1] = y;
    }
    else{
      dp[i][x][1] = max(dp[i][x][1], y);
      for(int j=0; j<W_MAX; j++){
        for(int k=0; k<N+1; k++){
          if(dp[i-1][j][k] != 0){
            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
            dp[i][j+x][k+1] = max(dp[i][j+x][k+1], dp[i-1][j][k] + y);
          }
        }
      }
    }
  }
  
  int64_t ans = 0;
  for(int i=0; i<W_MAX; i++){
    for(int j=0; j<N+1; j++){
      if(i + j*W_START <= W && dp[N-1][i][j] != 0){
        ans = max(ans,dp[N-1][i][j]);
      }
    }
  }
  cout << ans << endl; 
}  