#include<bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;

int n, K, ans, siz[N];
int f[N][N], h[N];
vector<int> g[N];

void dfs(int u, int fa) {
  siz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    for (int i = 0; i <= min(K, siz[u]); i++) {
      h[i] = min(h[i], f[u][i] + siz[v]);
      for (int j = 0; j <= min(K, siz[v]); j++) {
        if (i + j + 1 <= K) {
          h[max(i, j + 1)] = min(h[max(i, j + 1)], f[u][i] + f[v][j]);
        }
      }
    }
    siz[u] += siz[v];
    for (int k = 0; k <= min(K, siz[u]); k++) {
      f[u][k] = h[k];
      h[k] = n;
    }
  }
  // cout<<u<<"+++"<<endl;
  for (int k = 0; k <= K; k++) {
    // cout<<k<<" "<<f[u][k]<<" "<<n - siz[u]<<endl;
    ans = min(ans, f[u][k] + n - siz[u]);
  }
}

int main() {
  scanf("%d %d", &n, &K);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = n;
    }
  }
  for (int i = 0; i <= n; i++) {
    h[i] = n;
  }
  ans = n;
  dfs(1, 0);
  printf("%d\n", ans); 
  return 0;
}