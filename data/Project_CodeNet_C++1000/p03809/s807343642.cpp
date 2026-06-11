// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 100003;
long long a[N_MAX];
std::vector<int> g[N_MAX];

bool ans = 1;
long long dfs(int x, int fa) {
  if (g[x].size() == 1 && fa != 0) {
    return a[x];
  }
  long long val = g[x].size() > 1 ? 2 * a[x] : a[x];
  long long sum = 0, mx = 0;
  for (int y : g[x])
    if (y != fa) {
      long long temp = dfs(y, x);
      sum += temp;
      mx = max(temp, mx);
    }
  if (mx > a[x] || sum * 2 < val)
    ans = 0;
  if (fa == 0) {
    if (sum != val)
      ans = 0;
    return 0;
  }
  else {
    if (sum > val)
      ans = 0;
    return val - sum;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  
  dfs(1, 0);
  printf(ans ? "YES\n" : "NO\n");
  return 0;
}
