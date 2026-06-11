#include <bits/stdc++.h>

using namespace std;
using i64 = std::int_fast64_t;

struct edge {
  int from;
  int to;
  std::int_fast64_t cost;
};

const i64 INF = 1LL << 58;

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<edge> graph(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    i64 c;
    cin >> a >> b >> c;
    a--, b--;
    edge e = {a, b, c};
    graph[i] = e;
  }

  vector<i64> d(N, -INF);
  d[0] = 0;

  for (int i = 0; i < N; i++) {
    for (auto e : graph) {
      if (d[e.from] != -INF) chmax(d[e.to], d[e.from] + e.cost);
    }
  }
  i64 res = d[N - 1];
  for (int i = 0; i < N; i++) {
    for (auto e : graph) {
      if (d[e.from] != -INF) chmax(d[e.to], d[e.from] + e.cost);
    }
  }

  if (res < d[N - 1]) {
    cout << "inf" << '\n';
  } else {
    cout << res << '\n';
  }
  return 0;
}
