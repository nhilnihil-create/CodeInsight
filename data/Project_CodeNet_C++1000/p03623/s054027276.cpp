#include <stdio.h>

int main() {
  int W, A, B;
  scanf("%d %d %d", &W, &A, &B);
  int distA = (W > A) ? W - A : A - W;
  int distB = (W > B) ? W - B : B - W;
  (distA < distB) ? puts("A") : puts("B");
  return 0;
}