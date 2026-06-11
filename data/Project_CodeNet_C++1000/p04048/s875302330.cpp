#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 n, x;
    std::cin >> n >> x;
    i64 ret = n, a = x, b = n - x;
    while (true) {
        if (b > a) std::swap(a, b);
        if (a % b == 0) {
            ret += ((a / b) * 2 - 1) * b;
            break;
        } else {
            ret += a / b * b * 2;
            a = a % b;
        }
    }
    std::cout << ret << std::endl;

    return 0;
}
