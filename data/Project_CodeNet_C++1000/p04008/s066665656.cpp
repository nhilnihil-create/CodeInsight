#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 100000;
std::vector<int> g[1 + nmax];
int v[1 + nmax];

int dfs(int node, int &result, int k) {
  int acc = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    int acc2 = dfs(to, result, k);
    if(acc2 == k) {
      if(node != 1) {
        result++;
        acc2 = 0;
      }
    } else
      acc = std::max(acc, acc2);
  }
  return acc + 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  int far;
  std::cin >> far;
  int result = 0;
  if(far != 1)
    result++;
  for(int i = 2; i <= n; i++) {
    std::cin >> far;
    g[far].push_back(i);
  }
  dfs(1, result, k);
  std::cout << result;
}
