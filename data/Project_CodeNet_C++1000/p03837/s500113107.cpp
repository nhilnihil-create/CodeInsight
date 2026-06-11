#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

//-------------------------
// ダイクストラ
//-------------------------
struct edge {
  ll to;
  ll cost;
};

const ll MAX_N = 510;
ll N, M;
vector<edge> edges[MAX_N];
ll d[MAX_N];  // startからの最短距離
ll pv[MAX_N];

ll used[MAX_N][MAX_N];

void dijkstra(ll start) {
  // 距離が最小のものから処理するためのキュー
  priority_queue<pll, vector<pll>, greater<pll>> que;

  fill(d, d + MAX_N, INF);
  fill(pv, pv + MAX_N, -1);

  d[start] = 0;
  que.push(pll(0, start));

  while (!que.empty()) {
    pll p = que.top();
    que.pop();

    ll from = p.second;  // 頂点番号

    ll p_cost = p.first;
    if (d[from] < p_cost) {
      // 試す価値なし
      continue;
    }

    for (ll i = 0; i < edges[from].size(); i++) {
      edge e = edges[from][i];

      ll next_cost = d[from] + e.cost;
      if (d[e.to] > next_cost) {
        d[e.to] = next_cost;
        que.push(pll(d[e.to], e.to));

        //
        pv[e.to] = from;
      }
    }
  }
}

void calc() {
  scanf("%lld %lld", &N, &M);

  for (ll i = 0; i < M; i++) {
    ll from, to, cost;
    scanf("%lld %lld %lld", &from, &to, &cost);

    edges[from].emplace_back(edge{to, cost});
    edges[to].emplace_back(edge{from, cost});
  }

  for (ll start = 1; start <= N; start++) {
    dijkstra(start);

    for (ll goal = start + 1; goal <= N; goal++) {
      if (start == goal) {
        continue;
      }

      ll current = goal;
      // vll path;
      for (;;) {
        // path.emplace_back(current);
        if (current == start) {
          break;
        }
        ll next = pv[current];
        if (next == -1) {
          break;
        }

        used[current][next] = 1;
        used[next][current] = 1;

        // cout << current << " " << next << endl;

        current = next;
        // cout << "current:" << current << endl;
      }
    }
  }

  ll ans = 0;

  for (ll from = 1; from <= N; from++) {
    for (ll j = 0; j < edges[from].size(); j++) {
      auto e = edges[from][j];
      if (from >= e.to) {
        continue;
      }
      if (!used[from][e.to]) {
        ans++;
        // cout << from << " " << e.to << endl;
      }
    }
  }
  cout << ans << endl;
}

int main() { calc(); }
