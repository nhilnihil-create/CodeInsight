#include <stdio.h>

int main() {
  int x, a, b;
  scanf("%d %d %d", &x, &a, &b);

  int c = a - x;
  int d = b - x;

  if(c < 0) {
    c *= -1;
  }
  if(d < 0) {
    d *= -1;
  }
  if(c < d) {
    puts("A");
  }
  else {
    puts("B");
  }
  
  return 0;
}