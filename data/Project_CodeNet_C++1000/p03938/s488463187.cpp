#include <vector>
#include <stdio.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int p[n + 1];
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  int a[n + 1];
  int b[n + 1];
  int k = 30000;
  for (int i = 1; i <= n; ++i) {
    a[i] = i * k;
    b[i] = k * (n - i + 1);
  }

  for (int i = 1; i <= n; ++i) {
    a[p[i]] += i;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", a[i]);
    if (i == n) {
      puts("");
    } else {
      printf(" ");
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", b[i]);
    if (i == n) {
      puts("");
    } else {
      printf(" ");
    }
  }  
  return 0;
}
