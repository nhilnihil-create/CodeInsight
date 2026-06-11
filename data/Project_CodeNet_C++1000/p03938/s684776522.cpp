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
  i64 N;
  std::cin >> N;
  std::vector<i64> p;
  tools::read(p, N);
  std::transform(p.begin(), p.end(), p.begin(), [](const i64& p_i) { return p_i - 1; });

  std::vector<i64> a(N), b(N);
  for (i64 i = 0; i < N; ++i) {
    a[i] = i * N + 1;
    b[N - i - 1] = i * N + 1;
  }
  for (i64 i = 0; i < N; ++i) {
    a[p[i]] += i;
  }

  std::string delimiter = "";
  for (const i64& a_i : a) {
    std::cout << delimiter << a_i;
    delimiter = " ";
  }
  std::cout << std::endl;
  delimiter = "";
  for (const i64& b_i : b) {
    std::cout << delimiter << b_i;
    delimiter = " ";
  }
  std::cout << std::endl;
  return 0;
}