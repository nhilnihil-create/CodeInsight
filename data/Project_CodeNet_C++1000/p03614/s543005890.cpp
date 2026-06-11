#include <bits/stdc++.h>
using namespace std;

const int N = 100050;

int main() {
  int n, a, ans = 0, num = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    if ( i == a ) num++;
    else {
      ans += ( num + 1 ) / 2;
      num = 0;
    }
  }
  printf("%d\n", ans + ( num + 1 ) / 2 );
  return 0;
}
