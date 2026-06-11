#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

struct paircomp {
    using T = std::pair<long long, long long>;
    bool operator()(const T& l, const T& r) const {
        return l.first > r.first || (!(r.first > l.first) && l.second < r.second);
    }
};

int main() {
    long long n, t, count = 0, minimum;
    std::cin >> n;
    std::vector<long long> ret(n);
    /* remain, number */
    std::set<std::pair<long long, long long>, paircomp> s;
    for (auto i = 0ll; i < n; i++) {
        std::cin >> t;
        s.insert({ t, i });
    }

    //std::for_each(s.begin(), s.end(), [](auto& el) { std::cout << el.second << " " << el.first << std::endl; });

    minimum = s.begin()->second;
    while (!s.empty()) {
        auto curr = *s.begin();
        minimum = std::min(minimum, s.begin()->second);
        while (!s.empty() && s.begin()->first == curr.first) {
            s.erase(s.begin());
            count++;
        }
        ret[minimum] += (curr.first - (s.empty()?0:s.begin()->first)) * count;
    }

    for (auto el : ret) std::cout << el << std::endl;

    return 0;
}