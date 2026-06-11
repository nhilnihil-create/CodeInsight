#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

main() {
    int n;
    cin >> n;

    vector<vector<int64_t>> costs(n, vector<int64_t>(n, numeric_limits<int64_t>::max() / 4));
    int64_t total = 0;
    for (auto i : irange(0, n)) {
        for (auto j : irange(0, n)) {
            cin >> costs[i][j];
            if (i > j) {
                total += costs[i][j];
            }
        }
    }

    for (auto i : irange(0, n)) {
        for (auto j : irange(0, n)) {
            bool required = true;
            for (auto k : irange(0, n)) {
                if (k == i || k == j) {
                    continue;
                }

                // check triangle relation
                if (costs[i][k] + costs[k][j] < costs[i][j]) {
                    cout << -1 << endl;
                    return 0;
                }

                if (costs[i][k] + costs[k][j] == costs[i][j]) {
                    required = false;
                }
            }

            if (!required && i > j) {
                total -= costs[i][j];
            }
        }
    }

    cout << total << endl;
}
