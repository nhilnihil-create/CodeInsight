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
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int cur = 0, mi = 0;
    for (int i = 0; i < n; i++) {
        cur += s[i] == '(' ? 1 : -1;
        mi = std::min(mi, cur);
    }
    std::string ans;
    for (int i = 0; i < -mi; i++) ans += '(', cur++;
    ans += s;
    for (int i = 0; i < cur; i++) ans += ')';
    std::cout << ans << std::endl;
    return 0;
}
