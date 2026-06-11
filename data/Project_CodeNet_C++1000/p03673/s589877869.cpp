#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::deque<int> deq;
  bool is_rev = false;

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    if (is_rev) {
      deq.push_front(a);
    } else {
      deq.push_back(a);
    }

    is_rev = !is_rev;
  }

  std::vector<int> ans;
  for (auto it = deq.begin(); it != deq.end(); it++) {
    ans.push_back(*it);
  }

  if (is_rev) {
    std::reverse(ans.begin(), ans.end());
  }

  for (int i = 0; i < n; i++) {
    std::cout << ans[i];
    std::cout << (i == n - 1 ? "\n" : " ");
  }

  return 0;
}