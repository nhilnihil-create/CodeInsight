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

int main()
{
    int N;
    std::cin >> N;

    int64_t sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i;
        if (sum == N) {
            for (int j = 1; j <= i; ++j) {
                std::cout << j << std::endl;
            }
            return 0;
        }
        else if (sum > N) {
            auto diff = sum - N;
            for (int j = 1; j <=i; ++j) {
                if (j != diff) {
                    std::cout << j << std::endl;
                }
            }
            return 0;
        }
    }

    return 0;
}
