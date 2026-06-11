/**
 *    author:  tourist
 *    created: 02.09.2017 15:17:17       
**/
#include <bits/stdc++.h>

using namespace std;

int a[1234567];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == i) {
      if (i + 1 < n && a[i + 1] == i + 1) {
        ans++;
        i++;
        continue;
      }
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
