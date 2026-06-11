#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n;
vector<int> g[N];

int dfs(int u, int p) {
   int ans = 0;
   for (int v : g[u]) {
      if (v != p) {
         ans ^= (dfs(v, u) + 1);
      }
   }
   return ans;
}

int main() {
   scanf("%d", &n);
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   puts(dfs(1, -1) ? "Alice" : "Bob");
}
