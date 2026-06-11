#include <iostream>
#include <cstdio>

int n, m, k;
char s[4] = {'R', 'Y', 'G', 'B'};

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x = i + j + m, y = i - j + m;
      putchar(s[((x / k) & 1) * 2 + ((y / k) & 1)]); 
    }
    printf("\n");
  }
  return 0;
}
