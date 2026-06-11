#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  for(int i = 0; i < n; i++) cin >> x.at(i);
  
  long long dp[55][55][3000];
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      for(int k = 0; k < 3000; k++){
        int now = x.at(i);
        dp[i+1][j+1][k+now] += dp[i][j][k];
        dp[i+1][j][k] += dp[i][j][k];
      }
    }
  }
  
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    int j = i * a;
    ans += dp[n][i][j];
  }
  
  cout << ans << endl;
}