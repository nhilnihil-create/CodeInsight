#include <cstdio>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if(a * b * (a + b) % 3)
    printf("Impossible\n");
  else
    printf("Possible\n");
}