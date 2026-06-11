#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int mod = (int) 1e9 + 7;

int n, m;
int x[N], y[N];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", x + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", y + i);
  }
  int ans = 0;
  int sum_x = 0;
  for (int i = 0; i + 1 < n; i++) {
    int diff = x[i + 1] - x[i];
    int w = n - i - 1;
    sum_x = add(sum_x, mul(mul(w, i + 1), diff));
  }
  int sum_y = 0;
  for (int i = 0; i + 1 < m; i++) {
    int diff = y[i + 1] - y[i];
    int w = m - i - 1;
    sum_y = add(sum_y, mul(mul(w, i + 1), diff));
  }
  ans = mul(sum_x, sum_y);
  printf("%d\n", ans);
  return 0;
}