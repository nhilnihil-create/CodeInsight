#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

vector <int> g[N];
int a[N];
int k;

int ans;

int dfs(int v) {
  int sz = g[v].size();
  int steps = 0;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    int cur = dfs(u);
    steps = max(steps, cur + 1);
  }
  if (steps == k - 1 && a[v] != 0) {
    a[v] = 0;
    steps = -1;
    ans++;
  }
  return steps;
}

int main() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  ans = 0;
  if (a[0] != 0) {
    a[0] = 0;
    ans++;
  }
  for (int i = 1; i < n; i++) {
    g[a[i]].push_back(i);
  }
  dfs(0);
  printf("%d\n", ans);
  return 0;
}
