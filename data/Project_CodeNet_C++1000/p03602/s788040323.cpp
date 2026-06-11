#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

struct Link {
    int src;
    int dst;
    int64_t cost;

    bool operator<(const Link& rhs) const {
        return cost < rhs.cost;
    }
};

main() {
    int n;
    cin >> n;

    vector<Link> links;
    links.reserve(n * n);
    for (auto i : irange(0, n)) {
        for (auto j : irange(0, n)) {
            int64_t cost;
            cin >> cost;
            links.push_back(Link{i, j, cost});
        }
    }

    auto sorted_links = links;

    sort(sorted_links.begin(), sorted_links.end());

    vector<vector<int64_t>> costs(n, vector<int64_t>(n, -1));
    for (int i = 0; i < n; ++i) {
        costs[i][i] = 0;
    }

    int64_t total = 0;
    for (int i = 0; i < sorted_links.size(); ++i) {
        const auto& link = sorted_links[i];
        if (link.src <= link.dst) {
            continue;
        }

        if (costs[link.src][link.dst] >= 0 && link.cost > costs[link.src][link.dst]) {
            cout << "-1" << endl;
            return 0;
        }

        if (costs[link.src][link.dst] >= 0 && link.cost == costs[link.src][link.dst]) {
            continue;
        }

        total += link.cost;
        for (int i = 0; i < n; ++i) {
            if (costs[link.src][i] < 0) {
                continue;
            }

            for (int j = 0; j < n; ++j) {
                if (costs[link.dst][j] < 0) {
                    continue;
                }

                auto cost = costs[link.src][i] + link.cost + costs[link.dst][j];
                if (costs[i][j] >= 0 && cost >= costs[i][j]) {
                    continue;
                }

                costs[i][j] = cost;
                costs[j][i] = cost;
            }
        }
    }

    cout << total << endl;
}
