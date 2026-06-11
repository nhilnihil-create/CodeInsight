#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> G[N + 1];
bool used[N + 1];

bool ans = false;
int n, m;

void dfs(int u, int d) {
  if (d == 3 || ans) return;
  if (d == 2 && u == n) {
    ans = true;
    return;
  }
  used[u] = 1;
  for (int i = 0; i < G[u].size() && !ans; i++) {
    if (!used[G[u][i]])
      dfs(G[u][i], d + 1);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 0);
  if (ans) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
