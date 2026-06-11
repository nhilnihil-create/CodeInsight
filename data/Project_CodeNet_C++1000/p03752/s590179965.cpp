#include <iostream>
#include <cmath>

int next_combination(int bit) {
  int x = bit & -bit, y = bit + x;
  return (((bit & ~y) / x) >> 1) | y;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N, K;
  std::cin >> N >> K;

  uint64_t C[16]{0};
  uint64_t S[16]{0};

  uint64_t max = 0;
  int mi = 0;
  for (int i = 0; i < N; i++) {
    std::cin >> C[i];
    if (C[i] > max) {
      mi = i;
      max = C[i];
    }
  }

  int k = (1 << K) - 1;
  uint64_t out = UINT64_MAX;
  for (int bit = k; bit < (1 << N); bit = next_combination(bit)) {
    uint64_t last = 0;
    uint64_t cost = 0;
    for (int i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        uint64_t diff = 0;
        if (mi < i && last < max) {
          last = max;
        }
        if (C[i] <= last) {
          cost += (diff = last - C[i] + 1);
        }

        last = (C[i] + diff);
      }
    }

    out = std::min(out, cost);
  }

  std::cout << out << std::endl;
}
