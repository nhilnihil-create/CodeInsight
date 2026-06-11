#include <bits/stdc++.h>
using namespace std;

int n, x, now = 1;

int main() {
  scanf("%d%d", &n, &x);
  if (x == 1 || x == (2 * n - 1)) return puts("No"), 0;
  puts("Yes");
  for (int i = 1; i <= n - 2; i++) {
    while (now == x || now == x - 1 || now == x + 1) ++now;
    printf("%d\n", now++);
  }
  printf("%d\n%d\n%d\n", x - 1, x, x + 1);
  for (int i = 1; i <= n - 2; i++) {
    while (now == x || now == x - 1 || now == x + 1) ++now;
    printf("%d\n", now++);
  }
  return 0;
}
