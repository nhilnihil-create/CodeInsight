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
 
ll dfs(int v, int p) {
  vector<ll> edges;
  for (int u : G[v]) {
    if (u != p) {
      ll e = dfs(u, v);
      if (e < 0) {
        return -1;
      }
      edges.push_back(e);
    }
  }
  if (edges.empty()) {
    return A[v];
  }
  ll sum = accumulate(edges.begin(), edges.end(), 0ll);
  ll mx = *max_element(edges.begin(), edges.end());
  ll x = 2 * A[v] - sum;
  sum += x;
  mx = max(mx, x);
  if (x < 0 || mx > A[v]) {
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