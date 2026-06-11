#if !defined(__clang__) && defined(__GNUC__)
#include <bits/stdc++.h>
#else
#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <complex>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#endif //  !defined(__clang__) && defined(__GNUG__)
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>

using namespace std;

template<typename T>
T absi(T x) {
    if (x < static_cast<T>(0)) {
        x *= static_cast<T>(-1);
    }
    return x;
}

int main()
{
    int64_t N, T;
    std::cin >> N >> T;

    std::vector<int64_t> A;
    for (size_t i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        A.push_back(t);
    }

    std::vector<int64_t> costs;
    int64_t min = INT64_MAX;
    for (int64_t i = 0; i < N; ++i) {
        if (min < A[i]) {
            costs.push_back(A[i] - min);
        }
        min = std::min(min, A[i]);
    }
    #if 0
    for (int64_t i = 0; i < N-1; ++i) {
        for (int64_t j = i+1; j < N; ++j) {
            if (A[i] < A[j]) {
                costs.push_back(A[j] - A[i]);
            }
        }
    }
    #endif

    std::sort(std::begin(costs), std::end(costs),
              [](const auto& a, const auto& b) {
                  return a > b;
              });

    size_t count = 0;
    for (auto&& c: costs) {
        if (c != costs[0]) {
            break;
        }
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}
