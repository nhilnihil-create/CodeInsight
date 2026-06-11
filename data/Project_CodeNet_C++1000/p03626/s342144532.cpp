#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main() {
  int N;
  string S1,S2;
  cin >> N >> S1 >> S2;
  long long dp[N];
  dp[0] = (S1[0] == S2[0] ? 3 : 6);
  for (int i = 1; i < N; i++) {
    if (S1[i] == S1[i-1]) {
      dp[i] = dp[i-1];
    } else if (S1[i] == S2[i] && S1[i-1] == S2[i-1]) {
      dp[i] = 2*dp[i-1];
      dp[i] %= MOD;
    } else if (S1[i] == S2[i]) {
      dp[i] = dp[i-1];
    } else if (S1[i] != S2[i] && S1[i-1] == S2[i-1]) {
      dp[i] = 2*dp[i-1];
      dp[i] %= MOD;
    } else {
      dp[i] = 3*dp[i-1];
      dp[i] %= MOD;
    }
  }
  cout << dp[N-1];
}