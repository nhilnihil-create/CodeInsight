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

int N;
vector<ll> A;
vector<vector<int>> G;

ll countPairs(const vector<ll> &g) {
  ll sum = accumulate(g.begin(), g.end(), 0ll);
  ll mx = *max_element(g.begin(), g.end());
  return sum >= mx * 2 ? sum / 2 : sum - mx;
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

bool solve() {
  if (N == 2) {
    return A[0] == A[1];
  }
  int r = -1;
  for (int v = 0; v < N; v++) {
    if (G[v].size() > 1) {
      r = v;
      break;
    }
  }
  return dfs(r, -1) == 0;
}

int main() {
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
  cout << (solve() ? "YES" : "NO") << endl;
  return 0;
}
