#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, k, a[N], dep[N], ans;
vector<int> g[N];

void build(int a) {
  for (auto &b : g[a]) {
    dep[b] = 1 + dep[a];
    build(b);
  }
}

int dfs(int a) {
  int mx = dep[a];
  for (auto &b : g[a]) {
    int val = dfs(b);
    if (val - dep[a] >= k) {
      ans += (a != 1);
    } else {
      mx = max(mx, val);
    }
  }
  return mx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (a[1] != 1) {
    ans++;
    a[1] = 1;
  }
  for (int i = 2; i <= n; i++) {
    g[a[i]].push_back(i);
  }
  build(1);
  dfs(1);
  cout << ans << "\n";
}
