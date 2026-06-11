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
#if 0
struct Sq {
    int64_t x; // [0, W-3]
    int64_t y; // [0, H-3]

    bool operator==(const Sq& rhs) const {
        return rhs.x == x && rhs.y == y;
    }
    bool operator!=(const Sq& rhs) const {
        return !operator==(rhs);
    }
};

namespace std {
template <>
struct hash<Sq> {
    std::size_t operator()(const Sq& key) const {
        return std::hash<int64_t>()(key.x + key.y);
    }
};
} // namespace std
#endif


/* ソート済みの配列について、
   オブジェクトとその個数を得る。
 */
template<typename Itr, typename Fn>
void counting(Itr b, Itr e, Fn f) {
    if (b == e) {
        // no element;
        return;
    }
    size_t count = 0;
    auto&& itr = b;
    for (; itr + 1 != e; ++itr) {
        count++;
        if (*itr != *(itr + 1)) {
            f(*itr, count);
            count = 0;
        }
    }

    f(*itr, ++count);
}


int main()
{
    int64_t H, W, N;
    std::cin >> H >> W >> N;

    struct Sq {
        int64_t x; // [0, W-3]
        int64_t y; // [0, H-3]
        bool operator==(const Sq& rhs) const {
            return rhs.x == x && rhs.y == y;
        }
        bool operator!=(const Sq& rhs) const {
            return !operator==(rhs);
        }
    };

    std::vector<Sq> sqs;

    for (int64_t i = 0; i < N; ++i) {
        int64_t x, y;
        std::cin >> y >> x;
        x--; // [0, W-3]
        y--; // [0, H-3]
        for (int64_t xx = x - 2; xx <= x; ++xx) {
            for (int64_t yy = y - 2; yy <= y; ++yy) {
                if (xx >= 0 && yy >= 0 && xx <= W - 3 && yy <= H - 3) {
                    sqs.push_back({xx, yy});
                }
            }
        }
    }

    std::sort(std::begin(sqs), std::end(sqs),
              [](const auto& a, const auto& b) {
                  return a.x !=  b.x ? a.x < b.x : a.y < b.y;
              });

    std::vector<uint64_t> ans(10);
    ans[0] = (H-2) * (W-2);
    counting(sqs.begin(), sqs.end(),
             [&ans](auto, size_t count) -> void {
                 ans[count]++;
                 ans[0]--;
             });

    for (auto&& a: ans) {
        std::cout << a << std::endl;
    }

    return 0;
}
