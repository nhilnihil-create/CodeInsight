#include <bits/stdc++.h>

long long a[12345];

int main() {
  long long k;
  scanf("%lld", &k);
  int n = 50;
  for (int i = 0; i < n; i++) {
    a[i] = n - 1;
  }
  long long kn = (k + n - 1) / n * n;
  for (int i = 0; i < n; i++) {
    a[i] += kn / n;
  }
  while (kn > k) {
    --kn;
    for (int i = 0; i < n; i++) {
      if (a[i] >= n) {
        a[i] -= n;
        for (int j = 0; j < n; j++) if (j != i) a[j]++;
        break;
      }
    }
  }
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%lld", a[i]);
  }
  puts("");
}