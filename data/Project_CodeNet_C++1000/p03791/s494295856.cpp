#include <cstdio>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int n, x[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
  int ans = 1;
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= n && j - i <= (x[j - 1] + 1) / 2) ++j;
    ans = (i64)ans * (j - i) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
