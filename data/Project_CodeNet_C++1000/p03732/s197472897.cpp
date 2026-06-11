#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, W;
  cin >> N >> W;
  const int maxW = 3 * N;
  vector<int64_t> w(N);
  vector<int64_t> v(N);
  cin >> w[0] >> v[0];
  int64_t w0 = w[0];
  w[0] = 0;
  rep(i, N - 1) {
    cin >> w[i + 1] >> v[i + 1];
    w[i + 1] -= w0;
  }
  vector<vector<int64_t>> DP(N + 1, vector<int64_t>(maxW + 1, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = maxW; j >= 0; --j) {
      if ((j + w[i]) > maxW) continue;
      for (int k = N - 1; k >= 0; --k) {
        DP[k + 1][j + w[i]] = max(DP[k + 1][j + w[i]], DP[k][j] + v[i]);
      }
    }
  }

  int64_t answer = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = maxW; j >= 0; --j) {
      int64_t limW = w0 * (int64_t)i;
      if (limW + j > W) continue;
      answer = max(answer, DP[i][j]);
    }
  }
  cout << answer << endl;
  return 0;
}
