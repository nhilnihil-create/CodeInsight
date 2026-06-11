#include <bits/stdc++.h>

int main() {
    int n, ret = 0, cnt = 0, t;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> t;
        if (t == i) {
            cnt++;
        } else if (cnt > 0) {
            ret += (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ret += (cnt + 1) / 2;
    std::cout << ret << std::endl;

    return 0;
}