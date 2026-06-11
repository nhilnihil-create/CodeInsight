// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 200003;
long long init = 0xcfcfcfcfcfcfcfcf;
long long dp[N_MAX][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n >> dp[1][0];
  dp[1][1] = dp[1][2] = init;
  for (int i = 2; i <= n; ++i) {
    string op;
    int x;
    cin >> op >> x;
    if (op[0] == '-') {
      dp[i][0] = init;
      dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) - x;
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + x;
    }
    else {
      dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + x;
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]) - x;
      dp[i][2] = dp[i - 1][2] + x;
    }
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
  return 0;
}
