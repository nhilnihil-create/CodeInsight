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

int N, M, R;
int r[8];
ll A[330][330];

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  V = N;
  init_dist();

  rep(i, 0, R) { cin >> r[i]; }

  rep(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
  }

  warshall_floyd();

  sort(r, r + R);

  int ans = inf;
  do {
    int cnt = 0;
    rep(i, 0, R - 1) { cnt += dist[r[i]][r[i + 1]]; }
    chmin(ans, cnt);
  } while (next_permutation(r, r + R));

  cout << ans << endl;
}
