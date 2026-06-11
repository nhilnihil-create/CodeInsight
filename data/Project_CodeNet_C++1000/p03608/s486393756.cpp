#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXV = 220;
constexpr int INF = 1e9;

int dist[MAXV][MAXV];

int main() {
  int N, M, R;
  cin >> N >> M >> R;

  for (int i = 0; i < MAXV; i++) for (int j = 0; j < MAXV; j++) dist[i][j] = INF;

  vector<int> r(R);
  for (int i = 0; i < R; i++) {
    cin >> r[i];
    r[i]--;
  }

  for (int i = 0; i < M; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    a--, b--;

    dist[a][b] = c;
    dist[b][a] = c;
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  sort(r.begin(),r.end());
  int ans = INF;
  do {
    int tmp = 0;
    for (int i = 1; i < R; i++) {
      tmp += dist[r[i - 1]][r[i]];
    }
    ans = min(ans, tmp);
  } while(next_permutation(r.begin(),r.end()));

  cout << ans << '\n';
}