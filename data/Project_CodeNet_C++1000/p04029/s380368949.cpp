#include <iostream>

int N;

void solve() {
    std::cin >> N;
    std::cout << (1+N)*(N)/2 << std::endl;
}

int main() {
    solve();
    return 0;
}