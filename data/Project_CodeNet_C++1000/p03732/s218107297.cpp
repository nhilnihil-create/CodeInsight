#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, m;
    cin >> n >> m;
    vector < pair < int, int > > items(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> items[i].first >> items[i].second;
    vector < map < int, int > > knapsack(n + 1);
    knapsack[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto reach: knapsack[i - 1]) {
            knapsack[i][reach.first] = max(knapsack[i][reach.first], reach.second);
            if (reach.first + items[i].first <= m)
                knapsack[i][reach.first + items[i].first] = reach.second + items[i].second;
        }
    }
    int ans = 0;
    for (auto reach: knapsack.back())
        ans = max(ans, reach.second);
    cout << ans << '\n';
}
