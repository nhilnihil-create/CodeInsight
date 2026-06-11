#include <bits/stdc++.h>
using i64 = long long;

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

bool rec(std::vector<i64> &v, bool first = true) {
    const i64 sum = std::accumulate(v.begin(), v.end(), 0ll);
    const int n = v.size();
    const int odd = std::count_if(v.begin(), v.end(), [](i64 k) { return k % 2 == 1; });
    if ((sum - n) % 2) return first;
    else if (n == 1 || odd != 1) return !first;

    for (auto &e : v) if (e % 2) {
        if (e == 1) return !first;
        --e;
        break;
    }
    const i64 g = std::accumulate(v.begin(), v.end(), 0ll, gcd);
    for (auto &e : v) e /= g;
    return rec(v, !first);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &e : a) std::cin >> e;
    std::cout << (rec(a) ? "First" : "Second") << std::endl;

    return 0;
}
