#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using vll = vector<ll>;

void solve();

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}

#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)

#define inl(...)  \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)

#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__);

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}

void out() {
  cout << endl;
}
template <typename T, class... U>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u))
    cout << " ";
  out(u...);
}

#define rep(i, n) for (long long i = 0; i < n; i++)

void solve();
#ifndef ONLINE_JUDGE
#include "./lib.hpp"
#endif

struct edge {
  ll from, to, cost;
};

void solve() {
  inl(N, M);

  vector<edge> edges;
  rep(i, M) {
    inl(a, b, c);
    a--, b--;
    edges.push_back(edge{a, b, -c});
  }

  vll d(N, 1LL << 60);
  d[0] = 0LL;

  ll memo = 0;
  rep(i, 2 * N) {
    bool update = false;
    for (auto e : edges) {
      if (d[e.from] != (1LL << 60) && d[e.to] > d[e.from] + e.cost)
        d[e.to] = d[e.from] + e.cost;
    }

    if (i == N - 1)
      memo = d[N - 1];
  }
  if (memo != d[N - 1])
    out("inf");
  else
    out(-d[N - 1]);
}
