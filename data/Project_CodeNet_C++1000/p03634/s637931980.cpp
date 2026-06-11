#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> edg(n);
    std::vector<std::vector<long long>> cost(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        a--; b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    int q, k; std::cin >> q >> k;
    k--;
    std::vector<long long> dist(n, 1e18);
    std::priority_queue<std::pair<long long, int>> que;
    que.emplace(0, k);
    dist[k] = 0;
    while (!que.empty()) {
        int pos = que.top().second;
        que.pop();
        for (int i = 0; i < (int)edg[pos].size(); i++) {
            int u = edg[pos][i];
            long long c = cost[pos][i];
            if (dist[u] <= dist[pos] + c) continue;
            dist[u] = dist[pos] + c;
            que.emplace(-dist[u], u);
        }
    }
    while (q--) {
        int x, y; std::cin >> x >> y;
        x--; y--;
        std::cout << dist[x] + dist[y] << std::endl;
    }
    return 0;
}
