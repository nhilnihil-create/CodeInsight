#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  string A;
  cin >> A;
  A = '$' + A;
  int N = A.size();
  vector<vector<int>> next(N, vector<int>(26, N));
  for (int i = N - 1; i >= 1; i--){
    next[i - 1] = next[i];
    next[i - 1][A[i] - 'a'] = i;
  }
  vector<int> dp(N + 1, INF);
  dp[N] = 0;
  for (int i = N - 1; i >= 0; i--){
    for (int j = 0; j < 26; j++){
      dp[i] = min(dp[i], dp[next[i][j]] + 1);
    }
  }
  string ans = "";
  int pos = 0;
  while (dp[pos] > 0){
    for (int i = 0; i < 26; i++){
      if (dp[next[pos][i]] == dp[pos] - 1){
        pos = next[pos][i];
        ans += 'a' + i;
        break;
      }
    }
  }
  cout << ans << endl;
}