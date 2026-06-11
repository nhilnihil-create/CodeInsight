#include <climits>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N, vector<int>(N, INT_MAX));
  rep(i, N) G[i][i] = 0;
  vector<int> A(M);
  vector<int> B(M);
  vector<int> C(M);
  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i];
    --B[i];
    G[A[i]][B[i]] = C[i];
    G[B[i]][A[i]] = C[i];
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        if (G[i][k] == INT_MAX || G[k][j] == INT_MAX) continue;
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  int answer = M;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (G[j][A[i]] + C[i] == G[j][B[i]]) {
        --answer;
        break;
      }
    }
  }
  cout << answer << endl;
  return 0;
}