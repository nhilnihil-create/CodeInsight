#include <iostream>

int a, b, h;

void solve() {
    std::cin >> a >> b >> h;
    std::cout << (a + b) * h / 2;
}

int main() {
    solve();
    return 0;
}