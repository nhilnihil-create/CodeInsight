#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

vector<ll> search(ll x, vector<vector<pair<ll, ll>>> &g) {
  priority_queue<pair<ll, ll>> q;
  vector<ll> memo(g.size(), INF);
  memo[x] = 0;
  q.push({0, x});
  while (!q.empty()) {
    ll len = q.top().first;
    ll pos = q.top().second;
    q.pop();
    if (memo[pos] < len) continue;
    for (auto next : g[pos]) {
      ll next_len = memo[pos] + next.second;
      if (next_len < memo[next.first]) {
        memo[next.first] = next_len;
        q.push({next_len, next.first});
      }
    }
  }
  return memo;
}

int main() {
  ll N;
  cin >> N;
  vector<vector<pair<ll, ll>>> g(N);
  ll a, b, c;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  ll Q, K;
  cin >> Q >> K;
  K--;
  vector<ll> dist = search(K, g);
  ll x, y;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y;
    x--, y--;
    cout << dist[x] + dist[y] << endl;
  }
}