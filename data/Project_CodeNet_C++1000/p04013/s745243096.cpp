#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N, A;
  cin >> N >> A;

  vector<int> x(N);
  rep(i, N) {
    cin >> x[i];
    x[i] -= A;
  }

  vector<vector<long long>> dp(N+1);
  rep(i, N+1) {
    dp[i].resize(2 * N * 50, 0);
  }
  dp[0][N*50] = 1;

  for(int i=1; i<=N; i++) {
    rep(j, 2*N*50) {
      dp[i][j] = dp[i-1][j] + dp[i-1][j-x[i-1]];
    }
  }

  cout << dp[N][N*50] - 1 << endl;

  return 0;
}
