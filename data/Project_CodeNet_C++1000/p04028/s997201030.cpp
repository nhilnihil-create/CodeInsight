#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;
const lint MOD = 1e9 + 7;
int N;
string s;
VVI dp(5010, VI(5010));

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  cin >> N >> s;
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i + 1; j++) {
      dp[i + 1][j] = ((j != 0 ? dp[i][j - 1] : dp[i][j]) + 2LL * dp[i][j + 1]) % MOD;
    }
  }
  cout << dp[N][s.size()] << '\n';
  return 0;
}