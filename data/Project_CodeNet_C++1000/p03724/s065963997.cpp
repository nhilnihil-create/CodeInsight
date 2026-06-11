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
    int n, m; std::cin >> n >> m;
    std::map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        int a, b; std::cin >> a >> b;
        cnt[a]++; cnt[b]++;
    }
    bool even = true;
    for (auto &p : cnt) {
        even &= ~p.second & 1;
    }
    std::cout << (even ? "YES" : "NO") << std::endl;
    return 0;
}
