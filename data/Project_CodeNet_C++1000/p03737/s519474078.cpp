#include <cstdio>

int main() {
  char a[10], b[10], c[10];
  scanf("%s %s %s", a, b, c);
  printf("%c%c%c\n", a[0] - 32, b[0] - 32, c[0] - 32);
}