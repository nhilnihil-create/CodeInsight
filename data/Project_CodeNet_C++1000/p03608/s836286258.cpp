#include <algorithm>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

vector<vector<LL>> d;

void warshal_floyd(int V) {
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int N, M, R; cin >> N >> M >> R;
  d.resize(N, vector<LL>(N, 1e18));

  vector<int> r(R);
  for (int i = 0; i < R; ++i) {
    cin >> r[i];
    --r[i];
  }

  for (int i = 0; i < N; ++i) d[i][i] = 0;
  for (int i = 0; i < M; ++i) {
    LL a, b, t; cin >> a >> b >> t;
    --a, --b;
    d[a][b] = min(d[a][b], t);
    d[b][a] = min(d[b][a], t);
  }

  warshal_floyd(N);

  LL vmin = LLONG_MAX;

  sort(r.begin(), r.end());
  do {
    LL cost = 0;
    for (int j = 1; j < R; ++j) cost += d[r[j-1]][r[j]];
    vmin = min(vmin, cost);
  } while(next_permutation(r.begin(), r.end()));

  cout << vmin << endl;
}
