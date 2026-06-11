#include <bits/stdc++.h>
using i64 = long long;

std::vector<std::vector<int>> g;

int dfs(int v, int p) {
    std::vector<int> a;
    for (int to : g[v]) {
        if (to == p) continue;
        a.push_back(dfs(to, v));
    }
    if (a.empty()) return 0;
    std::sort(a.begin(), a.end(), std::greater<>());
    for (int i = 0; i < a.size(); i++) a[i] += i + 1;

    return *std::max_element(a.begin(), a.end());
}

int main() {
    int n;
    std::cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        --p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    std::cout << dfs(0, -1) << std::endl;

    return 0;
}
