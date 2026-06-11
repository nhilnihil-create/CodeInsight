#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, a;
  cin >> n >> a;
  
  vector<int> x(n);
  for(int i = 0; i < n; i++){
    cin >> x.at(i);
    x.at(i) -= a;
  }
  vector<vector<ll>> dp(51, vector<ll>(5001, 0));
  dp[0][2500] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 50; j < 4951; j++){
      dp[i + 1][j + x.at(i)] += dp[i][j];
      dp[i + 1][j] += dp[i][j];
    }
  }
  
  cout << dp[n][2500] - 1 << '\n';
}