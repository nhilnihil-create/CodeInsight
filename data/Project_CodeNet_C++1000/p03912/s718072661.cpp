
#include <iostream>
#include <vector>

int main() {
  unsigned N, M;
  std::vector<unsigned> X(100002, 0u);
  std::cin >> N >> M;
  for (unsigned i = 0; i < N; ++i) {
    unsigned tmp;
    std::cin >> tmp;
    ++X[tmp];
  }
  std::vector<unsigned> odd(M, 0u);
  std::vector<unsigned> even(M, 0u);
  for (unsigned i = 0; i <= 100000; ++i) {
    if (M % 2 == 0 && i % M == M / 2) {
      odd[M / 2] += X[i];
      continue;
    }
    if (i % M == 0) {
      odd[0] += X[i];
      continue;
    }
    if (X[i] % 2) {
      ++odd[i % M];
    }
    even[i % M] += X[i] / 2;
  }
  unsigned ans = 0u;
  for (unsigned i = 1; i < (M + 1) / 2; ++i) {
    unsigned min_i;
    unsigned max_i;
    if (odd[i] < odd[M - i]) {
      min_i = i;
      max_i = M - i;
    } else {
      min_i = M - i;
      max_i = i;
    }
    ans += odd[min_i];
    odd[max_i] -= odd[min_i];
    if (odd[max_i] <= even[min_i] * 2) {
      ans += odd[max_i];
      even[min_i] *= 2;
      even[min_i] -= odd[max_i];
      ans += even[min_i] / 2;
      ans += even[max_i];
    } else {
      ans += even[min_i] * 2;
      ans += even[max_i];
    }
  }
  ans += odd[0] / 2;
  if (M % 2 == 0) {
    ans += odd[M / 2] / 2;
  }
  std::cout << ans;
  return 0;
}
