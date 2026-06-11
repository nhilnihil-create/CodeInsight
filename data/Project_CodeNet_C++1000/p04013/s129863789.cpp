#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  for (int i = 0; i < (int)N; ++i) {
    cin >> x[i];
    x[i] = A - x[i];
  }

  int M = 101, zero = 50 * N;

  vector<vector<ll>> dp(N + 1, vector<ll>(M * N + 1, 0));
  dp[0][zero] = 1;
  for (int i = 0; i < (int)N; ++i) for (int j = 0; j < (int)N * M + 1; ++j) {
    dp[i + 1][j] = dp[i][j];
    int pj = j - x[i];
    if (0 <= pj && pj <= N * M) dp[i + 1][j] += dp[i][pj];
  }

  cout << dp[N][zero] - 1 << endl;
  return 0;
}
