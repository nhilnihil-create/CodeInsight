#include <stdio.h>

int main() {
  int X, A, B;
  scanf("%d %d %d", &X, &A, &B);
  int distA = (X > A) ? X - A : A - X;
  int distB = (X > B) ? X - B : B - X;
  printf("%c\n", (distA < distB) ? 'A' : 'B');
  return 0;
}
