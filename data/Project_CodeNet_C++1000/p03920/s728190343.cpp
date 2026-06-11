#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int tot = 0, i;
  for (i = 1; tot + i <= n; tot += i, i ++);
  i --;
  int tg = i + 1 - (n - tot);
  for (int j = 1; j <= i; j ++) {
    if (j == tg) printf("%d\n", i + 1);
    else printf("%d\n", j);
  }
}
