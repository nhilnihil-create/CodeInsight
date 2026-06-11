#include <bits/stdc++.h>

using namespace std;

const int64_t INF = INT64_C(1) << 60;

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
  vector<pair<int, pair<int, int>>> E(M);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    E[i] = make_pair(a, make_pair(b, c));
  }
  vector<int64_t> D(N, -INF);
  D[0] = 0;
  for (int i = 0; i < N; i++) {
    for (auto e : E) {
      int u = e.first, v = e.second.first, d = e.second.second;
      if (D[u] != -INF) chmax(D[v], D[u] + d);
    }
  }
  for (int i = 0; i < N; i++) {
    for (auto e : E) {
      int u = e.first, v = e.second.first, d = e.second.second;
      if (D[u] != -INF && chmax(D[v], D[u] + d)) D[v] = INF;
    }
  }
  if (D[N - 1] == INF) {
    cout << "inf" << '\n';
  } else {
    cout << D[N - 1] << '\n';
  }
  return 0;
}
