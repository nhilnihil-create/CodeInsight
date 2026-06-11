#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

int main() {
  std::string A;
  std::cin >> A;
  std::vector<bool> used('z' - 'a' + 1, false);
  std::vector<int> segment(A.size() + 1, 0);
  auto cnt = 'z' - 'a' + 1;
  auto seg_cnt = 0;
  segment[A.size()] = -1;
  for (auto i = A.size(); i > 0; --i) {
    segment[i - 1] = seg_cnt;
    if (!used[A[i - 1] - 'a']) {
      used[A[i - 1] - 'a'] = true;
      --cnt;
      if (cnt == 0) {
        ++seg_cnt;
        cnt = 'z' - 'a' + 1;
        std::fill(used.begin(), used.end(), false);
      }
    }
  }

  std::vector<std::vector<int>> idx('z' - 'a' + 1);
  for (unsigned i = 0; i < A.size(); ++i) {
    idx[A[i] - 'a'].push_back(i);
  }
  for (auto &i : idx) { i.push_back(A.size()); }

  int pos = 0;
  for (int l = seg_cnt; l > -1; --l) {
    for (int i = 0; i < 'z' - 'a' + 1; ++i) {
      auto p = std::lower_bound(idx[i].begin(), idx[i].end(), pos);
      if (*p == (int) A.size() || segment[*p] == l - 1) {
        std::cout << (char) ('a' + i);
        pos = *p + 1;
        break;
      }
    }
  }
  return 0;
}