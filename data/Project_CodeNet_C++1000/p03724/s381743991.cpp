#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    int a, b;
    std::unordered_map<int, int> m;
    for (int i = 0; i < M; ++i) {
        std::cin >> a >> b;
        m[a] += 1;
        m[b] += 1;
    }

    for (const auto& p : m) {
        if (p.second % 2 != 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}
