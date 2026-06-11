#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int>> edge(n);
  for (int i = 0; i < m; i++) {
    int from, to;
    scanf("%d%d", &from, &to);
    from--, to--;
    edge[from].emplace_back(to);
    edge[to].emplace_back(from);
  }

  for (int i : edge[0]) {
    for (int j : edge[i]) {
      if (j == n-1) {
        printf("POSSIBLE\n");
        return 0;
      }
    }
  }

  printf("IMPOSSIBLE\n");
  return 0;
}