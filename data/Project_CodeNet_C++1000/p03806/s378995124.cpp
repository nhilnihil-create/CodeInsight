#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N, MA, MB;
  cin >> N >> MA >> MB;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  rep(i, N) cin >> A[i] >> B[i] >> C[i];

  vector<vector<vector<int>>> DP(
      N + 1, vector<vector<int>>(401, vector<int>(401, 1e5)));
  DP[0][0][0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int a = 400; a >= 0; --a) {
      if ((a + A[i]) > 400) continue;
      for (int b = 400; b >= 0; --b) {
        if ((b + B[i]) > 400) continue;
        DP[i + 1][a][b] = DP[i][a][b];
        DP[i + 1][a + A[i]][b + B[i]] =
            min(DP[i + 1][a + A[i]][b + B[i]], DP[i][a][b] + C[i]);
      }
    }
  }

  int answer = 1e5;
  rep(i, N) {
    for (int a = 1; a <= 400; ++a) {
      for (int b = 1; b <= 400; ++b) {
        // a : b == MA : MB
        if (a * MB != b * MA) continue;
        answer = min(answer, DP[i + 1][a][b]);
      }
    }
  }
  if (answer == 1e5)
    cout << -1 << endl;
  else
    cout << answer << endl;
  return 0;
}
