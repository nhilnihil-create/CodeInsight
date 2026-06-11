#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, K;
  cin >> n >> K;
  vector<int> edge[n+1], dep(n+1);
  function<void(int, int)> dfs = [&](int u, int fa) {
    for ( auto v : edge[u]) {
      if( v ^ fa) {
        dep[v] = dep[u] + 1; dfs(v, u);
      }
    }
  };
  for ( int i = 2, x, y; i <= n; ++ i) {
    cin >> x >> y;
    edge[x].push_back(y); edge[y].push_back(x);
  }
  int ans = 1e9;
  if( K & 1) {
    for ( int i = 1; i <= n; ++ i) {
      for ( auto v : edge[i]) {
        if( v < i) {
          continue;
        }
        int ret = 0;
        dep[i] = dep[v] = 0;
        dfs(i, v); 
        dfs(v, i);
        for ( int k = 1; k <= n; ++ k) {
          if( dep[k] > K >> 1) {
            ++ ret;
          }
        }
        ans = min(ans, ret);
      }
    }
  } else {
    for ( int i = 1; i <= n; ++ i) {
      dfs(i, dep[i] = 0);
      int ret = 0;
      for ( int k = 1; k <= n; ++ k) {
        if( dep[k] > K >> 1) {
          ++ ret;
        }
      }
      ans = min(ans, ret);
    }
  }
  cout << ans << "\n";
  return 0;
}