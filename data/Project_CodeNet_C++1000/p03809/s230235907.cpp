#include <iostream>
#include <vector>

#define int long long
#define MAXN 200000

int a[MAXN];
int n;
std::vector<int> Adj[MAXN];

int dfs(int u, int p = -1) {
  int ret = a[u];

  if(Adj[u].size() == 1 && p != -1)
    return ret;

  int sum = 0;
  int max = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;

    int next = dfs(j, u);

    if(next == -1)
      return -1;

    sum += next;
    max = std::max(max, next);
  }

  ret = 2*a[u] - sum;

  if(ret < std::max(2*max - sum, (int)0) || a[u] > sum)
    return -1;

  return ret;
}

signed main() {
  std::cin >> n;

  for(int i = 0; i < n; i++) 
    std::cin >> a[i];

  int root = 0;
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);

    if(Adj[u].size() > 1)
      root = u;
    if(Adj[v].size() > 1)
      root = v;
  }

  if((dfs(root) == 0 && n > 2) || (n == 2 && a[0] == a[1]))
    std::cout << "YES";
  else
    std::cout << "NO";

  std::cout << std::endl;

  return 0;
}
