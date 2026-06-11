#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

typedef long long ll;
typedef vector<int> VI;
typedef pair<ll, ll> PL;

const int N = 123456;
ll a[N];
VI edges[N];


ll dfs(int v, int par) {
  vector<ll> pool;
  ll tot = 0;
  rep(i, edges[v].size()) {
    int w = edges[v][i];
    if (w == par) { continue; }
    ll sub = dfs(w, v);
    if (sub < 0) {
      return -1;
    }
    pool.push_back(sub);
    tot += sub;
  }
  ll rest = 0;
  if (par == -1) {
    if (pool.size() >= 2 && tot != 2 * a[v]) {
      return -1;
    }
    if (pool.size() == 1 && tot != a[v]) {
      return -1;
    }
  } else {
    rest = pool.size() >= 1 ? 2 * a[v] - tot : a[v];
    if (rest < 0) {
      return -1;
    }
    pool.push_back(rest);
  }
  sort(pool.rbegin(), pool.rend());
  if (pool.size() >= 2 && pool[0] > a[v]) {
    return -1;
  }
  if (pool.size() == 1) {
    if (pool[0] != a[v]) {
      return -1;
    }
    return a[v];
  }
  return rest;
}

int main(void) {
  int n;
  cin >> n;
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  ll result = dfs(0, -1);
  cout << (result >= 0 ? "YES" : "NO") << endl;
}
