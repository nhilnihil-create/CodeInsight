#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef ::std::int_fast64_t i64;
typedef ::std::uint_fast64_t u64;
typedef ::std::int_fast32_t i32;
typedef ::std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(::std::istream& is, ::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    vector.reserve(size);
    ::std::copy_n(::std::istream_iterator<T>(is), size, ::std::back_inserter(vector));
  }
  template <typename T>
  void read(::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    ::tools::read(::std::cin, vector, size);
  }

  template <typename T, ::std::size_t N>
  void read(::std::istream& is, ::std::array<T, N>& array) {
    ::std::copy_n(std::istream_iterator<T>(is), N, array.begin());
  }
  template <typename T, ::std::size_t N>
  void read(::std::array<T, N>& array) {
    ::tools::read(::std::cin, array);
  }
}

#endif

// main.cpp

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; ++i) {
    std::cin >> A[i] >> B[i];
  }

  std::unordered_set<i64> options;
  for (i64 i = 0; i < N; ++i) {
    options.insert(i);
  }
  i64 answer = 0;

  for (i64 i = 29; i >= 0; --i) {
    if (((K >> i) & 1) == 0) {
      auto it = options.begin();
      while (it != options.end()) {
        if (((A[*it] >> i) & 1) == 0) {
          ++it;
        } else {
          it = options.erase(it);
        }
      }
    } else {
      i64 possible_answer = 0;
      for (const i64& option : options) {
        if (((A[option] >> i) & 1) == 0) {
          possible_answer += B[option];
        }
      }
      answer = std::max(answer, possible_answer);
    }
  }
  answer = std::max(answer, std::accumulate(options.begin(), options.end(), static_cast<i64>(0), [&](const i64& sum, const i64& option) { return sum + B[option]; }));

  std::cout << answer << std::endl;
  return 0;
}