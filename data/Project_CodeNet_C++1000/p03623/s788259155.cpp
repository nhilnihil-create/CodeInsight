#include <stdio.h>

int main() {
  int x, a, b;
  scanf("%d %d %d", &x, &a, &b);

  int k = a - x;
  int o = b - x;

  if(k < 0) {
    k *= -1;
  }

  if(o < 0) {
    o *= -1;
  }

  if(k < o) {
    puts("A");
  }
  else {
    puts("B");
  }
  return 0;
}