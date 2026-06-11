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
    int a, b, c; std::cin >> a >> b >> c;
    std::cout << (a <= c && c <= b ? "Yes" : "No") << std::endl;
    return 0;
}
