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
    int k; std::cin >> k;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') continue;
        int t = 'z' - s[i] + 1;
        if (t <= k) {
            s[i] = 'a';
            k -= t;
        }
    }
    s.back() = ((int)s.back() - 'a' + k) % 26 + 'a';
    std::cout << s << std::endl;
    return 0;
}