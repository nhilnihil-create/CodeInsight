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

  if (N == 1) {
    std::cout << "Yes" << std::endl;
    std::cout << 1 << std::endl;
    goto FINISHED;
  }
  if (x == 1 || x == 2 * N - 1) {
    std::cout << "No" << std::endl;
    goto FINISHED;
  }
  if (x == N) {
    std::cout << "Yes" << std::endl;
    for (i64 i = 1; i <= 2 * N - 1; ++i) {
      std::cout << i << std::endl;
    }
    goto FINISHED;
  }
  if (x < N) {
    std::vector<i64> left;
    left.reserve(2 * N - 5);
    for (i64 i = 1; i <= 2 * N - 1; ++i) {
      if (i != 1 && i != x && i != 2 * N - 2 && i != 2 * N - 1) {
        left.push_back(i);
      }
    }
    std::cout << "Yes" << std::endl;
    for (i64 i = 0; i < (N - 2) - 1; ++i) {
      std::cout << left[i] << std::endl;
    }
    std::cout << 2 * N - 2 << std::endl;
    std::cout << 1 << std::endl;
    std::cout << x << std::endl;
    std::cout << 2 * N - 1 << std::endl;
    for (i64 i = (N - 2) - 1; i < 2 * N - 5; ++i) {
      std::cout << left[i] << std::endl;
    }
    goto FINISHED;
  }
  if (x > N) {
    std::vector<i64> left;
    left.reserve(2 * N - 5);
    for (i64 i = 1; i <= 2 * N - 1; ++i) {
      if (i != 1 && i != 2 && i != x && i != 2 * N - 1) {
        left.push_back(i);
      }
    }
    std::cout << "Yes" << std::endl;
    for (i64 i = 0; i < (N - 2) - 1; ++i) {
      std::cout << left[i] << std::endl;
    }
    std::cout << 1 << std::endl;
    std::cout << 2 * N - 1 << std::endl;
    std::cout << x << std::endl;
    std::cout << 2 << std::endl;
    for (i64 i = (N - 2) - 1; i < 2 * N - 5; ++i) {
      std::cout << left[i] << std::endl;
    }
    goto FINISHED;
  }

FINISHED:
  return 0;
}