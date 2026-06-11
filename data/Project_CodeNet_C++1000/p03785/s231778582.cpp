#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  uint32_t N = 0, C = 0, K = 0;
  std::cin >> N >> C >> K;

  std::vector<uint32_t> T(N);
  for (auto &&t : T) std::cin >> t;
  std::sort(T.begin(), T.end());

  uint32_t sum = 1, first = T[0], riders = 1;
  for (size_t i = 1; i < N; i++) {
    if (riders == C || first + K < T[i]) {
      sum++;
      riders = 1;
      first = T[i];
    } else {
      riders++;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}