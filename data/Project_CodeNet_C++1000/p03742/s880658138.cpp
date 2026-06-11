#include <stdio.h>

int main(void) {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  if(a >= b - 1 && a <= b + 1) printf("Brown");
  else printf("Alice");
  return 0;
}