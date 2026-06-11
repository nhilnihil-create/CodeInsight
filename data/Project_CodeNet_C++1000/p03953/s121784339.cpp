#include <bits/stdc++.h>
using namespace std;

// the base of 10^18 = 60

typedef long long ll;
const int maxn = 1e5 + 10;
ll k, a[maxn];
int n, m, data[maxn], pos[61][maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i), data[i] = i;
  }
  scanf("%d %lld", &m, &k);
  for (int i = 1, x; i <= m; i++) {
    scanf("%d", &x);
    swap(data[x], data[x + 1]);
  }
  for (int i = 1; i <= n; i++) {
    pos[0][i] = data[i];
  }
  for (int i = 1; i < 61; i++) {
    for (int j = 1; j <= n; j++) {
      pos[i][j] = pos[i - 1][pos[i - 1][j]];
    }
  }
  for (int i = 1; i <= n; i++) {
    data[i] = i;
  }
  for (int p = 60; ~p; p--) {
    if (k >> p & 1) {
      for (int i = 1; i <= n; i++) {
        data[i] = pos[p][data[i]];
      }
    }
  }
  static int c[maxn];
  for (int i = 1; i <= n; i++) {
    c[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + c[data[i]];
    printf("%lld\n", a[i]);
  }
  return 0;
}