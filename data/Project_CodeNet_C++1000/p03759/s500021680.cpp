#include <bits/stdc++.h>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if ((b - a) == (c - b)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
