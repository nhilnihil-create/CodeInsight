#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    i64 ret = 0;
    int min = 1;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a == min) min++;
        else ret += (a - 1) / min;

        if (min == 1) min++;
    }
    std::cout << ret << std::endl;

    return 0;
}
