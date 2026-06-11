#include <bits/stdc++.h>

const int N = 100;

int n, count[N];

bool solve() {
  int d = n - 1;
  while (!count[d]) {
    d--;
  }
  for (int i = 0; i <= d; ++i) {
    int x = std::max(i, d - i);
    if (!count[x]) {
      return false;
    }
    count[x]--;
  }
  for (int i = 1; i < d; ++i) {
    int x = std::max(i, d - i) + 1;
    if (x < n) {
      count[x] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (count[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  while (scanf("%d", &n) == 1) {
    memset(count, 0, sizeof(count));
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      count[a]++;
    }
    puts(solve() ? "Possible" : "Impossible");
  }
}
