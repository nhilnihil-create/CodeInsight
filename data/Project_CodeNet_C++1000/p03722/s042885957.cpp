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


struct Edge {
  int from;
  int to;
  LL cost;
};

// detect closed-loop -> return false,  else return true.
bool belman_ford(int s, int g, int V, const vector<Edge>& es, vector<LL>* d) {
  d->resize(V, LLONG_MAX);
  d->at(s) = 0;

  for (int i = 0; i < V; ++i) {
    bool update = false;
    for (const Edge& e : es) {
      if (d->at(e.from) == LLONG_MAX) continue;
      if (d->at(e.to) > d->at(e.from) + e.cost) {
        d->at(e.to) = d->at(e.from) + e.cost;
        update = true;
        if (i == V-1 && e.to == g) return false;
      }
    }
    // finish
    if (!update) {
      break;
    }
  }
  return true;
}

int main() {
  int N, M; cin >> N >> M;
  vector<Edge> es;
  for (int i = 0; i < M; ++i) {
    int a, b, c; cin >> a >> b >> c;
    --a, --b;
    es.push_back({a, b, -c});
  }

  vector<LL> d;
  if (belman_ford(0, N-1, N, es, &d)) {
    cout << -d[N-1] << endl;
  } else {
    cout << "inf" << endl;
  }
}
