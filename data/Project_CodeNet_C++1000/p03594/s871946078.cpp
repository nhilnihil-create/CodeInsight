#include <cstdio>

int main() {
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  if (d % 2 == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        putchar("RG"[(i + j) & 1]);
      }
      puts("");
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        int first = (i + j) % (2 * d);
        int second = ((i - j) % (2 * d) + 2 * d) % (2 * d);
        int color = (first < d) * 2 + (second < d);
        putchar("RGBY"[color]);
      } else {
        int first = (i - 1 + j) % (2 * d);
        int second = (((i - 1) - j) % (2 * d) + 2 * d) % (2 * d);
        int color = (first < d) * 2 + (second < d);
        putchar("RGBY"[color]);
      }
    }
    puts("");
  }
}
