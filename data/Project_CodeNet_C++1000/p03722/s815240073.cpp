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

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

const long long MAX_E = 10101;
const long long MAX_V = 10101;

struct edge {
  long long from, to, cost;
};

edge es[MAX_E];

long long dist[MAX_V];
long long V, E;

bool negloop[MAX_V];

void shortest_path(long long s) {
  for (int i = 1; i <= V; i++) dist[i] = MINF;

  dist[s] = 0;

  ll cnt = 0;

  while (true) {
    ++cnt;

    bool updated = false;
    for (int i = 1; i <= E; i++) {
      edge e = es[i];
      if (dist[e.from] != MINF && dist[e.to] < dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        updated = true;
        if (cnt >= V) {
          negloop[e.to] = true;
        }
      }
      if (negloop[e.from]) {
        negloop[e.to] = true;
      }
    }
    if (!updated) break;

    if (cnt >= 2 * V) break;
  }
}

ll N, M;

int main() {
  cin >> N >> M;
  V = N;
  E = M;
  repe(i, 1, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    es[i] = edge{a, b, c};
  }

  shortest_path(1);

  if (negloop[N]) {
    cout << "inf";
  } else {
    cout << dist[N];
  }
}
