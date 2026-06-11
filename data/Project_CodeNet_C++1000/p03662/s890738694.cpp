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


int main()
{
    int64_t N;
    std::cin >> N;

    using G = std::unordered_map<int64_t, std::vector<int64_t>>;

    G g;

    for (size_t i = 0; i < N-1; ++i) {
        int64_t a, b;
        std::cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::vector<int64_t> dfe(N, -1);
    std::vector<int64_t> dsu(N, -1);

    auto f = [&dfe, &g](auto F, int dist, int64_t from, int64_t prev) -> void {
        dfe[from] = dist;
        for (auto& to: g[from]) {
            if (dfe[to] == -1 && to != prev) {
                F(F, dist+1, to, from);
            }
        }
    };

    f(f, 0, 0, -1);

    auto s = [&dsu, &g](auto F, int dist, int64_t from, int64_t prev) -> void {
        dsu[from] = dist;
        for (auto& to: g[from]) {
            if (dsu[to] == -1 && to != prev) {
                F(F, dist+1, to, from);
            }
        }
    };
    s(s, 0, N-1, -1);

    size_t b, w;
    b = w = 0;
    for (size_t i = 0; i < N; ++i) {
        if (dfe[i] <= dsu[i]) {
            b++;
        }
        else {
            w++;
        }
    }
    if (b > w) {
        std::cout << "Fennec" << std::endl;
    }
    else {
        std::cout << "Snuke" << std::endl;
    }

    return 0;
}
