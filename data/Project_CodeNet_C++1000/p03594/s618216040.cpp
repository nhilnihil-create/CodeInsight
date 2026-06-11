#include <cstdio>

int H, W, d;
char c[4] = {'R', 'Y', 'G', 'B'};

int main() {
  scanf("%d %d %d", &H, &W, &d);
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      int x = (i + j + W) / d % 2;
      int y = (i - j + W) / d % 2;
      putchar(c[x * 2 + y]);
    }
    puts("");
  }
  return 0;
}