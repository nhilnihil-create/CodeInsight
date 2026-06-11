#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> city(R);
  rep(i, R) {
    cin >> city[i];
    --city[i];
  }
  sort(city.begin(), city.end());

  const int INF = 100000000;
  vector<vector<int>> G(N, vector<int>(N, INF));
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    G[a][b] = c;
    G[b][a] = c;
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        if (G[i][k] == INF || G[k][j] == INF) continue;
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  int answer = INF;
  do {
    int dist = 0;
    rep(i, R - 1) { dist += G[city[i]][city[i + 1]]; }
    answer = min(answer, dist);
  } while (next_permutation(city.begin(), city.end()));
  cout << answer << endl;
  return 0;
}