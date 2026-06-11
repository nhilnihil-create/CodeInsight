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
    std::string s; std::cin >> s;
    std::vector<std::string> t = { "dream", "dreamer", "erase", "eraser" };
    std::reverse(s.begin(), s.end());
    for (int i = 0; i < 4; i++) std::reverse(t[i].begin(), t[i].end());
    int pos = 0;
    while (pos < s.size()) {
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            if (s.substr(pos, t[i].size()) == t[i]) {
                pos += t[i].size();
                flag = false;
            }
        }
        if (flag) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}
