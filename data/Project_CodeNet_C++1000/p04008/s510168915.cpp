#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, k;
int a[maxn];
bool visited[maxn];
int res = 0;
int d[maxn];
vector <int> edge[maxn];

void dfs(int u) {
  visited[u] = true;
  d[u] = 0;
  for (int v : edge[u]) {
    if (visited[v]) continue;
    dfs(v);
    d[u] = max(d[u], d[v] + 1);
  }
  if (d[u] == k - 1 && a[u] != 1) {
    a[u] = 1;
    d[u] = -1;
    res++;
  }
}

int solve() {
  if (k == 1) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != 1) res++;
    }
    return res;
  }
  for (int i = 2; i <= n; i++) {
    edge[a[i]].push_back(i);
  }
  res += (a[1] != 1);
  a[1] = 1;
  dfs(1);
  return ::res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << solve();
}