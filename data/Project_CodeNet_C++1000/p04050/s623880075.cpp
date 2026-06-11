#include <bits/stdc++.h>

const int N = 100000;

int n, a[N];

bool solve() {
  std::vector<int> nums[2];
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    nums[a[i] & 1].push_back(a[i]);
  }
  if (static_cast<int>(nums[1].size()) > 2) {
    return false;
  }
  std::vector<int> a, b;
  if (static_cast<int>(nums[1].size()) >= 2) {
    a.push_back(nums[1][1]);
  }
  for (auto &&x : nums[0]) {
    a.push_back(x);
  }
  if (static_cast<int>(nums[1].size()) >= 1) {
    a.push_back(nums[1][0]);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], " \n"[i == n - 1]);
  }
  if (n == 1) {
    if (a[0] > 1) {
      b.push_back(a[0] - 1);
    }
    b.push_back(1);
  } else {
    if (a[0] > 1) {
      b.push_back(a[0] - 1);
    }
    for (int i = 1; i < n - 1; ++i) {
      b.push_back(a[i]);
    }
    b.push_back(a[n - 1] + 1);
  }
  int m = static_cast<int>(b.size());
  printf("%d\n", m);
  for (int i = 0; i < m; ++i) {
    printf("%d%c", b[i], " \n"[i == m - 1]);
  }
  return true;
}

int main() {
  while (scanf("%*d%d", &n) == 1) {
    if (!solve()) {
      puts("Impossible");
    }
  }
}
