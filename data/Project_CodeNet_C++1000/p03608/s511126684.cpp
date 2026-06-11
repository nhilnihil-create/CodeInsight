#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 987654321;

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r(R);
  for (int i = 0; i < R; i++) {
    cin >> r[i];
    r[i]--;
  }
  sort(r.begin(), r.end());

  vector<vector<int>> dist(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }

  int A, B, C;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    A--, B--;
    dist[A][B] = dist[B][A] = C;
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }

  int ret = INF;
  do {
    int tmp = 0;
    for (int i = 0; i < R - 1; i++) {
      tmp += dist[r[i]][r[i + 1]];
    }
    ret = min(ret, tmp);
  } while (next_permutation(r.begin(), r.end()));
  cout << ret << endl;
}