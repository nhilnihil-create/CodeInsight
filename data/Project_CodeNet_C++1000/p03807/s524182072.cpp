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
#include <cstring>


int main() {
    int n; std::cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        cnt += a & 1;
    }
    std::cout << (~cnt & 1 ? "YES" : "NO") << std::endl;
    return 0;
}