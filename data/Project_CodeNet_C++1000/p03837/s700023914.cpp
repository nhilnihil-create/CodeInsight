#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
const int MAX_V = 330;
int V;

long long dist[MAX_V][MAX_V];

void init_dist() {
  for (int i = 0; i < MAX_V; ++i) {
    for (int j = 0; j < MAX_V; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
      }
    }
  }
}

void warshall_floyd() {
  // 1-indexed
  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

ll N, M;
struct edge {
  ll from, to, cost;
};
edge es[2000];

int main() {
  cin >> N >> M;
  V = N;
  init_dist();
  rep(i, 0, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
    es[i] = edge{a, b, c};
  }

  warshall_floyd();

  ll ans = 0;
  rep(i, 0, M) {
    auto cv = es[i];
    bool used = false;
    repe(i, 1, N) {
      if (dist[i][cv.from] + cv.cost == dist[i][cv.to]) {
        used = true;
        break;
      }
    }
    if (!used) {
      ans++;
    }
  }

  cout << ans;
}
