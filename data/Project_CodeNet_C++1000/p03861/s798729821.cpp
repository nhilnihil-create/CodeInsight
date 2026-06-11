#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, b, x, ans = 0LL;
  scanf("%ld%ld%ld", &a, &b, &x);
  if(a == 0 && b == 0) ans = 1;
  else if(a == 0) ans = b / x + 1;
  else ans = b / x - (a - 1) / x;
  printf("%ld", ans);
}