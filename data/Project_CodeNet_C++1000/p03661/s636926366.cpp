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

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>

using namespace std;

int64_t absi(int64_t a) {
    return (a > 0) ? a : (a * -1);
}

int main()
{
    int64_t N;
    std::cin >> N;

    int64_t S = 0;
    std::vector<int64_t> a;
    for (int64_t i = 0; i < N; ++i) {
        int64_t t;
        std::cin >> t;
        S += t;
        a.push_back(t);
    }

    int64_t minDiff = INT64_MAX;
    int64_t x = a[0];
    int64_t y = S - a[0];
    for (int64_t i = 1; i < N; ++i) {
        minDiff = std::min(minDiff, absi(x - y));
        x += a[i];
        y -= a[i];
    }

    std::cout << minDiff << std::endl;

    return 0;
}
