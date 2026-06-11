#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main() {
    using VertexId = std::uint32_t;
    using EdgeId = std::uint64_t;
    using EdgeWeight = std::uint64_t;

    const auto invalid_distance = std::numeric_limits<EdgeWeight>::max();

    auto n = VertexId(0);
    auto m = EdgeId(0);
    auto r = VertexId(0);
    std::cin >> n >> m >> r;

    auto perm = std::vector<VertexId>();
    for (auto i_ = 0; i_ < r; ++i_) {
        auto v = VertexId(0);
        std::cin >> v;

        perm.emplace_back(v - 1);
    }

    auto map = std::vector<std::vector<EdgeWeight>>(n, std::vector<EdgeWeight>(n, invalid_distance));
    for (auto i_ = 0; i_ < m; ++i_) {
        auto source = VertexId(0);
        auto target = VertexId(0);
        auto weight = EdgeWeight(0);
        std::cin >> source >> target >> weight;

        map[source - 1][target - 1] = weight;
        map[target - 1][source - 1] = weight;
    }

    for (auto k = 0; k < n; ++k) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if ((map[k][i] != invalid_distance && map[k][j] != invalid_distance) &&
                    (map[k][i] + map[k][j] < map[i][j])) {
                    map[i][j] = map[k][i] + map[k][j];
                    map[j][i] = map[k][i] + map[k][j];
                }
            }
        }
    }

    std::sort(perm.begin(), perm.end());

    auto min_distance = invalid_distance;
    do {
        auto sum_distance = EdgeWeight(0);
        for (auto i = 0; i < r - 1; ++i) {
            sum_distance += map[perm[i]][perm[i + 1]];
        }

        if (sum_distance < min_distance) min_distance = sum_distance;
    } while (std::next_permutation(perm.begin(), perm.end()));

    std::cout << min_distance << std::endl;

    return 0;
}