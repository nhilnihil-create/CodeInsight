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
// 少し多めに確保すること
// ぴったりだと正しく動かないので注意
const long long MAX_V = 1010101;

struct edge {
  long long to, cost;
};

using Pll = pair<long long, long long>;

long long V;
vector<edge> Graph[MAX_V];
long long dist[MAX_V];

void dijkstra(long long s) {
  priority_queue<Pll, vector<Pll>, greater<Pll>> que;

  // 0-indexedと1-indexedの両方に対応
  fill(dist, dist + MAX_V, INF);

  dist[s] = 0;
  que.push(Pll(0, s));

  while (!que.empty()) {
    auto elem = que.top();
    que.pop();

    auto cv = elem.second;

    if (elem.first > dist[cv]) {
      continue;
    }

    for (auto e : Graph[cv]) {
      if (dist[e.to] > dist[cv] + e.cost) {
        dist[e.to] = dist[cv] + e.cost;
        que.push(Pll(dist[e.to], e.to));
      }
    }
  }
}

bool used[200][200];

ll N, M;

void dfs(int cur, int cost) {
  for (auto nv : Graph[cur]) {
    if (dist[nv.to] == cost + nv.cost) {
      used[cur][nv.to] = true;
      used[nv.to][cur] = true;
      dfs(nv.to, cost + nv.cost);
    }
  }
}

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    Graph[a].push_back(edge{b, c});
    Graph[b].push_back(edge{a, c});
  }

  repe(i, 1, N) {
    dijkstra(i);
    dfs(i, 0);
  }

  ll ans = 0;
  repe(i, 1, N) {
    auto cv = Graph[i];
    for (auto nv : cv) {
      if (!used[i][nv.to]) {
        ++ans;
      }
    }
  }
  cout << ans / 2 << endl;
}
