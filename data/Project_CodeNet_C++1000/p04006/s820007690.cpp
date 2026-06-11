#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef std::int_fast64_t i64;
typedef std::uint_fast64_t u64;
typedef std::int_fast32_t i32;
typedef std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(std::vector<T>& vector, const typename std::vector<T>::size_type size) {
    vector.reserve(size);
    std::copy_n(std::istream_iterator<T>(std::cin), size, std::back_inserter(vector));
  }

  template <typename T, std::size_t N>
  void read(std::array<T, N>& array) {
    std::copy_n(std::istream_iterator<T>(std::cin), N, array.begin());
  }
}

#endif

// main.cpp

int main() {
  i64 N, x;
  std::cin >> N >> x;
  std::vector<i64> a;
  tools::read(a, N);

  // dp[i][j] ... 魔法をj回使う場合の、色i(0-based indexing)のスライムの素材になるスライムを捕獲するのにかかる最低時間
  std::vector<std::vector<i64>> dp(N, std::vector<i64>(N));
  for (i64 i = 0; i < N; ++i) {
    dp[i][0] = a[i];
    for (i64 j = 1; j < N; ++j) {
      dp[i][j] = std::min(dp[i][j - 1], a[(i - j + N) % N]);
    }
  }

  i64 answer = std::numeric_limits<i64>::max();
  for (i64 j = 0; j < N; ++j) {
    i64 possible_answer = 0;
    for (i64 i = 0; i < N; ++i) {
      possible_answer += dp[i][j];
    }
    possible_answer += x * j;
    answer = std::min(answer, possible_answer);
  }

  std::cout << answer << std::endl;
  return 0;
}