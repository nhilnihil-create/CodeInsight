#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(void) {
  int N, A;
  cin >> N >> A;
  vector<int> X(N);
  rep(i, N) { cin >> X[i]; }

  vector<vector<vector<int64_t>>> DP(
      N + 1, vector<vector<int64_t>>(N + 1, vector<int64_t>(2501, 0)));
  DP[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k <= 2500; ++k) {
        DP[i + 1][j][k] += DP[i][j][k];
        if ((k + X[i]) <= 2500) DP[i + 1][j + 1][k + X[i]] += DP[i][j][k];
      }
    }
  }
  int64_t answer = 0;
  for (int i = 1; i <= N; ++i) {
    answer += (int64_t)DP[N][i][i * A];
  }
  cout << answer << endl;
  return 0;
}
