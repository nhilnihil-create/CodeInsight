#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <map>
#include <set>
#include <list>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        puts("0");
        return 0;
    }
    if (a == std::max(a, std::max(b, c))) {
        std::cout << (long long) b * (long long) c; 
        return 0;
    }
    if (b == std::max(a, std::max(b, c))) {
        std::cout << (long long) a * (long long) c; 
        return 0;
    }
    if (c == std::max(a, std::max(b, c))) {
        std::cout << (long long) b * (long long) a; 
        return 0;
    }
    return 0;
}