#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<vector<int>> vec(N,vector<int>(3));
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      cin >> vec.at(i).at(j);
    }
  }
  
  int dp[N][N*10+1][N*10+1]; //i番目までにaがx(g)、bがy(g)できる最小コスト
  
  int INF = 100000000;
  for(int i=0; i<N; i++){
    for(int j=0; j<N*10+1; j++){
      for(int k=0; k<N*10+1; k++){
        dp[i][j][k] = INF;
      }
    }
  }
  
  for(int i=0; i<N; i++){
    int a = vec.at(i).at(0);
    int b = vec.at(i).at(1);
    int c = vec.at(i).at(2);
    if(i == 0){
      dp[0][a][b] = c;
    }
    else{
      dp[i][a][b] = min(dp[i][a][b],c);
      for(int j=0; j<N*10+1; j++){
        for(int k=0; k<N*10+1; k++){
          if(dp[i-1][j][k] != INF){
            dp[i][j+a][k+b] = min(dp[i][j+a][k+b], dp[i-1][j][k] + c);
            dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
          }
        }
      }
    }
  }
  
  int ans = INF;
  
  for(int j=0; j<N*10+1; j++){
    for(int k=0; k<N*10+1; k++){
      if(dp[N-1][j][k] != INF && (A*k == B*j)){
        ans = min(ans,dp[N-1][j][k]);
      }
    }
  }
  
  
  if(ans == INF){
    cout << -1 << endl;
  }
  else{
    cout << ans << endl;
  }
}