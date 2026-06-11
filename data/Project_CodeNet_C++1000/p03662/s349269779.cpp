#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = n-1; i >= 0; --i)
#define REP(i, s, n) for (int i = s; i< (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
ll inf = ll(1e18);
using ll1d = vector<ll>;
using ll2d = vector<ll1d>;
using ll3d = vector<ll2d>;

template<class Len = int>
class Dijkstra {
 private:
  int n;
  std::vector<std::vector<std::pair<int, Len> > > edges;
 public:
  explicit Dijkstra(int n) : n(n), edges(n) {}

  void add_edge(int from, int to, Len cost) {
    edges[from].push_back(std::pair<int, Len>(to, cost));
  }

  std::vector<Len> solve(int source) {
    const Len inf = 1e16;
    typedef std::pair<Len, int> pi;
    std::vector<Len> d(n, inf);
    std::priority_queue<pi, std::vector<pi>, std::greater<pi> > que;
    que.push(pi(0, source));
    while (!que.empty()) {
      pi p = que.top();
      que.pop();
      int idx = p.second;
      if (d[idx] <= p.first) {
        continue;
      }
      d[idx] = p.first;
      for (int j = 0; j < edges[idx].size(); ++j) {
        que.push(pi(p.first + edges[idx][j].second, edges[idx][j].first));
      }
    }
    return d;
  }
};

void solve(istream &ccin = cin, ostream &ccout = cout) {
  ll n;
  ccin >> n;
  Dijkstra<ll> dij(n);
  rep(i, n - 1) {
    ll a, b;
    ccin >> a >> b;
    --a;
    --b;
    dij.add_edge(a, b, 1);
    dij.add_edge(b, a, 1);
  }
  ll1d fennec = dij.solve(0);
  ll1d sunuk = dij.solve(n - 1);
  ll cntf = 0, cnts = 0;
  rep(i, n) {
    if (fennec[i] <= sunuk[i]) {
      ++cntf;
    } else {
      ++cnts;
    }
  }

  if (cntf > cnts) {
    ccout << "Fennec" << endl;
  } else {
    ccout << "Snuke" << endl;
  }

}

int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
