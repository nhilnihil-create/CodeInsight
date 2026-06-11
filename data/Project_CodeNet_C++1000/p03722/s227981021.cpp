#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].push_back(make_pair(c, b));
  }
  vector<vector<long long>> dp(N * 2 + 2, vector<long long>(N, -INF));
  dp[0][0] = 0;
  for (int i = 0; i <= N * 2; i++){
    for (int j = 0; j < N; j++){
      dp[i + 1][j] = dp[i][j];
    }
    for (int j = 0; j < N; j++){
      if (dp[i][j] != -INF){
        for (auto P : E[j]){
          dp[i + 1][P.second] = max(dp[i + 1][P.second], dp[i][j] + P.first);
        }
      }
    }
  }
  if (dp[N - 1][N - 1] != dp[N * 2 + 1][N - 1]){
    cout << "inf" << endl;
  } else {
    cout << dp[N - 1][N - 1] << endl;
  }
}