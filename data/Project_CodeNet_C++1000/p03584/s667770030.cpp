// Copyright 2020 yaito3014
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;
  unsigned int K;
  std::cin >> N >> K;
  std::vector<unsigned int> A(N);
  std::vector<long long> B(N);
  for (int i = 0; i < N; ++i) std::cin >> A[i] >> B[i];
  long long ans = 0;
  for (int r = 0; r <= 30; ++r) {
    unsigned int X = K >> r << r | ((1 << r) - 1) >> 1;
    if (X > K) continue;
    long long sum = 0;
    for (int i = 0; i < N; ++i)
      if (!(A[i] & ~X))
        sum += B[i];
    ans = std::max(ans, sum);
  }
  std::cout << ans << '\n';
}
