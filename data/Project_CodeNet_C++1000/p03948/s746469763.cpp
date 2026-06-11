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

constexpr int64_t DIV1097 = 1000000007LL;

using namespace std;

int main()
{
    int64_t N, T;
    std::cin >> N >> T;

    auto cmp = [](const auto &l, const auto &r) {return l > r;};
    std::map<int64_t, int64_t, decltype(cmp)> D(cmp);
    int64_t prev = 0;
    for (decltype(N) i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;

        if (i == 0) {
            prev = t;
        }

        if (t > prev) {
            D[t - prev]++;
        }
        else {
            prev = t;
        }
    }

    cout << D.begin()->second << endl;

    return 0;
}
