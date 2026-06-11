#include <iostream>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>

int main() {
    long long n, b, s;
    std::cin >> n >> s;
    std::bitset<30> k(s);
    std::deque<std::bitset<30>> q;
    q.push_back(k);
    for (auto i = 0; i < 30; i++) {
        if (k[i]) {
            k.flip(i);
            q.push_back(k);
            k.flip(i);
        } else {
            k.flip(i);
        }
    }
    std::vector<long long> ret(q.size());

    //std::for_each(q.begin(), q.end(), [](auto& x) { std::cout << x << std::endl; });

    for (auto j = 0ll; j < n; j++) {
        std::cin >> s >> b;
        std::bitset<30> a(s);
        for (decltype(q.size()) i = 0ll; i < q.size(); i++) {
            if ((q[i] | a) == q[i]) ret[i] += b;
        }
    }

    std::cout << *std::max_element(ret.begin(), ret.end()) << std::endl;

    return 0;
}