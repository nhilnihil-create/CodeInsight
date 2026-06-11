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
#include <boost/math/common_factor_rt.hpp>

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
    int64_t N;
    std::cin >> N;

    int64_t total = 0;

    std::vector<int64_t> sum;
    for (size_t i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        total += t;
        sum.push_back(total);
    }

    int64_t min  = INT64_MAX;

    for (size_t i = 0; i < N-1; ++i) {
        auto x = sum[i];
        auto y = total - x;
        min = std::min(min, absi(x - y));
    }
    std::cout << min << std::endl;

    return 0;
}
