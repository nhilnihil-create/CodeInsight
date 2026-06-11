#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>

int main() {
    long long n, k, ret = 0;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    std::multiset<long long, std::greater<>> ms;
    std::map<long long, bool> m;
    for (auto i = 0ll; i < n; i++) {
        std::cin >> a[i];
        if (a[i] < k) ms.insert(a[i]);
    }

    for (auto i = 0ll; i < n; i++) {
        if (a[i] >= k) continue;
        if (m.find(a[i]) != m.end()) {
            ret += (m[a[i]] ? 1 : 0);
            continue;
        }
        m[a[i]] = true;
        std::bitset<5000> bs;
        ret++;
        auto flg = true;
        for (auto num : ms) {
            if (num == a[i] && flg) {
                flg = false;
                continue;
            }
            bs = bs | (bs << num);
            bs[num] = 1;
            auto brk = false;
            for (auto l = k - a[i]; l < k; l++) {
                if (bs[l]) {
                    ret--;
                    m[a[i]] = false;
                    brk = true;
                    break;
                }
            }
            if (brk) break;
        }       
    }

    std::cout << ret << std::endl;

    return 0;
}