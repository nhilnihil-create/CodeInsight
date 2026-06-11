#include <cstdio>
#include <vector>

const int N = 100000 + 10;

int n;
std::vector<int> adj[N];

int dfs(int a, int fa = -1) {
  int res = 0;
  for (auto b : adj[a]) if (b != fa) res ^= dfs(b, a) + 1;
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  puts(dfs(1) ? "Alice" : "Bob");
  return 0;
}
