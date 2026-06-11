#include<bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

int n, a[N], b[N];

bool check(int val) {
  for (int i = 1; i <= n * 2 - 1; i++) {
    b[i] = (a[i] >= val);
  }
  for (int i = 0; i < n; i++) {
    if (b[n + i] == b[n + i + 1]) return b[n + i];
    if (b[n - i] == b[n - i - 1]) return b[n - i];
  }
  return b[1];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * 2 - 1; i++) {
    scanf("%d", &a[i]);
  }
  int l = 1, r = n * 2 - 1, res = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      l = mid + 1;
      res = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d\n", res);
  return 0;
}