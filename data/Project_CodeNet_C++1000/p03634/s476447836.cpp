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

ll N;
ll Q, K;

int main() {
  cin >> N;
  V = N;

  rep(i, 1, N) {
    ll a, b, c;
    cin >> a >> b >> c;
    Graph[a].push_back(edge{b, c});
    Graph[b].push_back(edge{a, c});
  }

  cin >> Q >> K;
  dijkstra(K);
  vector<ll> ans;
  rep(i, 0, Q) {
    ll x, y;
    cin >> x >> y;
    ans.push_back(dist[x] + dist[y]);
  }

  for (auto e : ans) {
    cout << e << "\n";
  }
}
