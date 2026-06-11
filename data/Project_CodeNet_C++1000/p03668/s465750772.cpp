#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

int const nmax = 100000;
std::vector<int> g[1 + nmax];
int nimber[1 + nmax];

void dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      nimber[node] ^= nimber[to] + 1;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  if(nimber[1] == 0)
    std::cout << "Bob";
  else
    std::cout << "Alice";
  return 0;
}
