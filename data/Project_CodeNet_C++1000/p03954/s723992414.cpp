#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;

int n, a[N];

bool chk(int x) {
  for (int i = 1; i < n; i++) {
    if ((a[n + i - 1] <= x) == (a[n + i] <= x)) {
      return a[n + i] > x;
    }
    if ((a[n - i + 1] <= x) == (a[n - i] <= x)) {
      return a[n - i + 1] > x;
    }
  }
  return a[1] > x;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n - 1; i++) {
    scanf("%d", &a[i]);
  }
  int l = 1, r = 2 * n - 1;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (chk(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
      ans = mid;
    }
  }
  printf("%d\n", ans);
  return 0;
}