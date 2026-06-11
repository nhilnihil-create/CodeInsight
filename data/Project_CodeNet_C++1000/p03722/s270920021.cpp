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

constexpr LL kInf = 1e18;
constexpr LL kNegativeLoop = -kInf;

struct Edge {
  int from;
  int to;
  LL cost;
};

vector<LL> belman_ford(int s, int V, const vector<Edge>& es) {
  vector<LL> d(V, kInf);
  d[s] = 0;

  for (int i = 0; i < 2 * V; ++i) {
    bool update = false;
    for (const Edge& e : es) {
      if (d[e.from] == kInf) continue;
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = (i < V - 1) ? d[e.from] + e.cost
                              : kNegativeLoop;
        update = true;
      }
    }
    // finish
    if (!update) {
      break;
    }
  }
  return d;
}

int main() {
  int N, M; cin >> N >> M;
  vector<Edge> es;
  for (int i = 0; i < M; ++i) {
    int a, b, c; cin >> a >> b >> c;
    --a, --b;
    es.push_back({a, b, -c});
  }

  auto d = belman_ford(0, N, es);
  if (d[N-1] != kNegativeLoop) {
    cout << -d[N-1] << endl;
  } else {
    cout << "inf" << endl;
  }
}
