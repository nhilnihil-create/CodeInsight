#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  if (a + b < b + c && a + b < a + c) {
    printf("%d", a + b);
  } else if (b + c < b + a && b + c < a + c) {
    printf("%d", c + b);
  } else {
    printf("%d", a + c);
  }
}