#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int N, K, A[100050];

struct edge {
  int src, dst;
  edge(int s, int d) : src(s), dst(d) { }
};
typedef vector<edge> edges;
typedef vector<edges> graph;

int res;
int dfs(const graph& g, int u, int p = -1) {
  int h = 0;
  for (const edge& e : g[u]) {
    chmax(h, 1 + dfs(g, e.dst, e.src));
  }

  if (h == K - 1 && p > 0) {
    ++res;
    return -1;
  }
  return h;
}

int main() {
  N = in();
  K = in();
  graph G(N);
  res = 0;
  for (int i = 0; i < N; ++i) {
    A[i] = in() - 1;
    if (i == 0 && A[0] != 0) {
      A[0] = 0;
      ++res;
    }
    if (i != 0) {
      G[A[i]].emplace_back(A[i], i);
    }
  }

  dfs(G, 0);

  printf("%d\n", res);

  return 0;
}
