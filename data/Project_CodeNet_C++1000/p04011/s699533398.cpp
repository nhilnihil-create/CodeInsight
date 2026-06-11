#include <cstdio>
#define max(x, y) ((x) < (y) ? (y) : (x))

int main() {
  int n, k, x, y;
  scanf("%d %d %d %d", &n, &k, &x, &y);
  printf("%d\n", x * n + (y - x) * max(n - k, 0));
}