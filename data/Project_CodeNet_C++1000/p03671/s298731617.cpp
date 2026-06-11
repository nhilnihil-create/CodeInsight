#include <bits/stdc++.h>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::printf("%d\n", std::min({a + b, b + c, c + a}));

    return 0;
}
