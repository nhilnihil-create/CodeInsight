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

using G = typename std::unordered_map<int64_t, std::vector<int64_t>>;

std::vector<int64_t>
grouping(G& g, const int64_t N)
{
    std::vector<int64_t> group(N, -1);

    for (int64_t i = 0; i < N; ++i) {
        auto f = [&g, &group, col=i](auto F, int64_t from, int64_t prev) -> void {
            group[from] = col;

            for (auto&& to: g[from]) {
                if (group[to] == -1 && to != prev) {
                    F(F, to, from);
                }
            }
        };

        if (group[i] == -1) {
            f(f, i, -1);
        }
    }
    return group;
}


int main()
{
    int64_t N, K, L;
    std::cin >> N >> K >> L;

    G road;
    for (int64_t i = 0; i < K; ++i) {
        int64_t p, q;
        std::cin >> p >> q;
        p--;
        q--;
        road[p].push_back(q);
        road[q].push_back(p);
    }

    G rail;
    for (int64_t i = 0; i < L; ++i) {
        int64_t r, s;
        std::cin >> r >> s;
        r--;
        s--;
        rail[r].push_back(s);
        rail[s].push_back(r);
    }

    const auto road_group = grouping(road, N);
    const auto rail_group = grouping(rail, N);

    std::unordered_map<int64_t, std::unordered_map<int64_t, int64_t>> m;

    // それぞれの都市が属しているグループを集計
    for (int64_t i = 0; i < N; ++i) {
        m[road_group[i]][rail_group[i]] ++;
    }

    // で、i番目の都市はm[道路グループ[i]][鉄道グループ[i]]に属しているから、
    // このループで都市の順番に印字可能。
    for (int64_t i = 0; i < N; ++i) {
        std::cout << m[road_group[i]][rail_group[i]] << " ";
    }

    return 0;
}
