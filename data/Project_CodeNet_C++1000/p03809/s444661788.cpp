#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> A;
vector<vector<int>> G;

ll countPairs(const vector<ll> &g) {
  ll sum = accumulate(g.begin(), g.end(), 0ll);
  ll mx = *max_element(g.begin(), g.end());
  return min(sum - mx, sum / 2);
}

ll dfs(int v, int p) {
  ll a = A[v];
  vector<ll> children;
  for (int u : G[v]) {
    if (u != p) {
      ll c = dfs(u, v);
      if (c < 0) {
        return -1;
      }
      children.push_back(c);
    }
  }
  if (children.empty()) {
    return a;
  }
  ll sum = accumulate(children.begin(), children.end(), 0ll);
  ll y = sum - a;
  ll x = a - y;
  if (x < 0 || y < 0 || countPairs(children) < y) {
    return -1;
  }
  return x;
}

int main() {
  int N;
  cin >> N;
  A.resize(N);
  G.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll v = dfs(0, -1);
  bool res = (G[0].size() > 1 ? v == 0 : v >= 0);
  cout << (res ? "YES" : "NO") << endl;
  return 0;
}
