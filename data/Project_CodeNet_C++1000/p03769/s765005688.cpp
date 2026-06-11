#include <bits/stdc++.h>

int main() {
    long long n;
    std::cin >> n;
    auto c = 0ll;
    while ((1ll << (c + 1)) - 1 <= n) c++;
    n -= (1ll << c) - 1;
    std::vector<long long> v;
    for (int i = 1; i <= c; i++) v.push_back(i);
    std::deque<long long> q;
    while (n) {
        auto i = 0ll;
        while ((1ll << (i + 1)) <= n) i++;
        q.push_back(i);
        n -= (1ll << i);
    }
    for (int i = 0; i < q.size(); i++) {
        v.insert(v.begin() + q[i],  c + i + 1);
    }

    std::cout << v.size() * 2 << std::endl;
    for (auto a : v) std::cout << a << " ";
    for (int i = 1; i <= c + q.size(); i++) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}