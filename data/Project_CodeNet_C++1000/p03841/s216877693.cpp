#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n * n + 1);
    std::map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        int t;
        std::cin >> t;
        pos[t] = i;
        a[t] = i;
    }
    
    auto it = a.begin() + 1;
    // auto bit = a.end() - 1;
    for (auto& el : pos) {
        auto cpos = el.first;
        auto cval = el.second;
        for (int i = 0; i < cval - 1; i++) {
            while (*it && it != a.end()) it++;
            if (it - a.begin() > cpos) {
                std::cout << "No" << std::endl;
                return 0;
            }
            *it = cval;
        }
    }

    it = a.end() - 1;
    for (auto el = pos.rbegin(); el != pos.rend(); el++) {
        auto cpos = el->first;
        auto cval = el->second;
        for (int i = 0; i < n - cval; i++) {
            while (*it && it != a.begin()) it--;
            if (it - a.begin() < cpos) {
                std::cout << "No" << std::endl;
                return 0;
            }
            *it = cval;
        }
    }

    std::cout << "Yes\n";
    for (int i = 1; i <= n * n; i++) std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}