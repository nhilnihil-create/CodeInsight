#include <iostream>
#include <vector>

int main() {
  uint32_t N = 0;
  std::cin >> N;
  std::vector<int32_t> A(N);
  for (auto &&a : A) std::cin >> a;

  uint32_t ans = 0;
  bool prev = false, start = false;
  for (size_t i = 1; i < N; i++) {
    if (A[i - 1] == A[i]) continue;
    if (A[i - 1] > A[i]) {
      bool flag = !prev && start;
      ans += flag;
      start = !flag;
      prev = true;
    } else {
      bool flag = prev && start;
      ans += flag;
      start = !flag;
      prev = false;
    }
  }

  std::cout << ans + 1 << std::endl;

  return 0;
}