#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,W,w,v,V=0;
  cin >> N >> W;
  map<int,int> dp[N+1];
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> w >> v;
    for (auto p : dp[i]) {
      dp[i+1][p.first] = max(dp[i+1][p.first],dp[i][p.first]);
      if (p.first+w <= W) {
        dp[i+1][p.first+w] = max(dp[i][p.first]+v,dp[i+1][p.first+w]);
      }
    }
  }
  for (auto p : dp[N]) {
    V = max(V,p.second);
  }
  cout << V;
}