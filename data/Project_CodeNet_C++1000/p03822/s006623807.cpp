#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

std::vector<vector<int>> graph;
std::vector<bool> used;

int Get(int v) {
    used[v] = true;
    std::vector<int> all;
    for (const auto& to : graph[v]) {
        if (!used[to]) {
            used[to] = true;
            all.push_back(Get(to));
        }
    }

    if (all.empty()) {
        return 0;
    }
    sort(all.begin(), all.end());
    int ans = 0;
    for (int i = 0; i < (int)all.size(); i++) {
        ans = max(ans, all[i] + (int)all.size() - i);
    }
    return ans;
}

int main(void) {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    used.resize(n);
    used.assign(n, false);
    graph.resize(n);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        graph[x - 1].push_back(i - 1);
    }
    cout << Get(0) << endl;
}
