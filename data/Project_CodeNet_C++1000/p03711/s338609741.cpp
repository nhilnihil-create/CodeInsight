#include <cstdio>

int main() {
  int x, y, g[13] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  scanf("%d %d", &x, &y);
  if(g[x] == g[y])
    printf("Yes\n");
  else
    printf("No\n");
}