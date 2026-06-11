#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using vi = vector<int>;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

constexpr int INF = 1e9;
int main() {
  int N, M, R; cin >> N >> M >> R;
  vi r(R);
  rep(i, R) {
    cin >> r[i]; --r[i];
  }

  vector<vi> edge(N, vi(N, INF));
  rep(i, M) {
    int a, b, c; cin >> a >> b >> c;
    --a, --b;
    edge[a][b] = edge[b][a] = c;
  }

  rep(k, N) rep(i, N) rep(j, N)
    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);

  int ans = INF;
  sort(begin(r), end(r));
  do {
    int tmp = 0;
    rep(i, R-1)
      tmp += edge[r[i]][r[i+1]];
    ans = min(ans, tmp);
  } while (next_permutation(begin(r), end(r)));

  cout << ans << endl;

  return 0;
}

