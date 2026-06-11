#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

// lib/detail/ceil_and_floor.hpp
#ifndef DETAIL_CEIL_AND_FLOOR_HPP
#define DETAIL_CEIL_AND_FLOOR_HPP

namespace tools {
  template <typename T>
  constexpr T floor(T lhs, T rhs);

  template <typename T>
  constexpr T ceil(T lhs, T rhs);

  template <typename T>
  constexpr T floor(const T lhs, const T rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        lhs / rhs :
      lhs < 0 && rhs >= 0 ?
        -ceil<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -ceil<T>(lhs, -rhs) :
        floor<T>(-lhs, -rhs);
  }

  template <typename T>
  constexpr T ceil(const T lhs, const T rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        (lhs - 1 + rhs) / rhs :
      lhs < 0 && rhs >= 0 ?
        -floor<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -floor<T>(lhs, -rhs) :
        ceil<T>(-lhs, -rhs);
  }
}

#endif

// lib/quo.hpp
#ifndef QUO_H
#define QUO_H

/*
a == tools:quo(a, b) * b + tools::mod(a, b)
0 <= tools::mod(a, b) < std::abs(b)
*/

namespace tools {
  template <typename T>
  constexpr T quo(const T lhs, const T rhs) {
    return lhs > 0 ? lhs / rhs : rhs > 0 ? -((-lhs - 1 + rhs) / rhs) : (-lhs - 1 + -rhs) / -rhs;
  }
}

#endif

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

// lib/floor.hpp
#ifndef FLOOR_HPP
#define FLOOR_HPP


/*
usage:

tools::floor(5, 3) // => 1 (i.e., floor(5 / 3))
*/

#endif

// lib/ceil.hpp
#ifndef CEIL_HPP
#define CEIL_HPP


/*
usage:

tools::ceil(5, 3) // => 2 (i.e., ceil(5 / 3))
*/

#endif

// lib/mod.hpp
#ifndef MOD_HPP
#define MOD_HPP


/*
a == tools:quo(a, b) * b + tools::mod(a, b)
0 <= tools::mod(a, b) < std::abs(b)
*/

namespace tools {
  template <typename T>
  constexpr T mod(const T lhs, const T rhs) {
    return lhs - quo(lhs, rhs) * rhs;
  }
}

#endif

// lib/round.hpp
#ifndef ROUND_HPP
#define ROUND_HPP


/*
usage:

tools::round(5, 3) => 2
*/

namespace tools {
  template <typename T>
  constexpr T round(const T lhs, const T rhs) {
    return std::abs(rhs) % 2 == 0
      ? mod(lhs, rhs) == std::abs(rhs) / 2
        ? floor(lhs, rhs) % 2 == 0
          ? floor(lhs, rhs)
          : ceil(lhs, rhs)
        : mod(lhs, rhs) < std::abs(rhs) / 2
          ? floor(lhs, rhs)
          : ceil(lhs, rhs)
      : mod(lhs, rhs) <= std::abs(rhs) / 2
        ? floor(lhs, rhs)
        : ceil(lhs, rhs);
  }
}

#endif

// main.cpp

int main() {
  i64 N, A, B, C, D;
  std::cin >> N >> A >> B >> C >> D;

  const i64 nearest_coefficient = std::max(-(N - 1), std::min(tools::round(2 * (B - A) + (C + D) * ((N - 1) % 2), 2 * (C + D)) * 2 - (N - 1) % 2, N - 1));
  const i64 acceptable_min = (2 * A + nearest_coefficient * (C + D) - (N - 1) * (D - C)) / 2;
  const i64 acceptable_max = (2 * A + nearest_coefficient * (C + D) + (N - 1) * (D - C)) / 2;
  std::cout << (acceptable_min <= B && B <= acceptable_max ? "YES" : "NO") << std::endl;
  return 0;
}