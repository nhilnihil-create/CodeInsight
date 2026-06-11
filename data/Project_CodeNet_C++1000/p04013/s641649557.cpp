#include <bits/stdc++.h>

using namespace std;

//long long dp[50][50][2501];

int main() {
  int n , a ; cin>>n>>a;
  vector<int>v(n);
  int s = 0;
  for(int& i : v){
    cin>>i;
    s += i;
  }
  //dp[0][0][0] = 1;
  vector<vector<long long>> dp(n + 1 , vector<long long>(2500 + 1, 0));
  dp[0][0] = 1;
  for(int i = 0 ; i < n; ++i){
    vector<vector<long long>> new_dp(n + 1 , vector<long long>(2500 + 1, 0));
    for(int j = 0 ; j < n; ++j){
      for(int k = 0 ;k <= 2500; ++k){
        if(dp[j][k]){
          new_dp[j + 1][k + v[i]] += dp[j][k];
          new_dp[j][k] += dp[j][k];
          // dp[i + 1][j + 1][k + v[i]] += dp[i][j][k];
          // dp[i + 1][j][k] += dp[i][j][k];
        }
      }
    }
    swap(dp , new_dp);
  }
  long long ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += dp[i][i * a];
  }
  cout<<ans<<"\n";
}