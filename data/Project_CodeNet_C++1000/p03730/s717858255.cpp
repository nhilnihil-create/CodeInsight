#include <bits/stdc++.h>

int main()
{
    int a, b, c;
    bool ans = false;
    std::cin >> a >> b >> c;
    for (int i = 1; i <= b; ++i) {
        if ((a * i) % b == c) {
            ans = true;
        }
    }
    if (ans) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}