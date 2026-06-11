#include <bits/stdc++.h>
#define ll long long
using namespace std;

/* 
 * g++ -std=c++17 main.cpp -o main
 */
int main() {
  ios::sync_with_stdio(false);
  int N,A;
  cin>>N>>A;
  vector<int> as(51);
  vector<vector<vector<ll>>> dp(51, vector<vector<ll>>(51, vector<ll>(2501)));
  dp[0][0][0] = 1;
  for(int i = 1; i<=N; i++) {
    int a;
    cin>>a;
    as[i] = a;
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      for(int k = 0; k <= A * N; k++) {
        dp[i][j][k] = dp[i-1][j][k];
      }
    }
    for(int j = 0; j < N; j++) {
      for(int k = 0; k <= A * N; k++) {
        dp[i][j+1][k+as[i]] += dp[i-1][j][k];
      }
    }
  }
  ll ans = 0;
  for (int j = 1; j <= N; j++) {
    ans += dp[N][j][j * A];
  }
  cout<<ans<<endl;

}
