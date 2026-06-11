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

class info {
public:
  i64 A, B;
};

namespace std {
  std::istream& operator>>(std::istream& is, info& self) {
    return is >> self.A >> self.B;
  }
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<info> info_list;
  tools::read(info_list, N);

  const auto it = std::max_element(info_list.begin(), info_list.end(), [](const info& x, const info& y) { return x.A < y.A; });
  std::cout << it->A + it->B << std::endl;

  return 0;
}