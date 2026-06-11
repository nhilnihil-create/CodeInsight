#include <iostream>

int N, K, X, Y;

void solve() {
    std::cin >> N >> K >> X >> Y;
    if (N < K)
        std::cout << N * X << std::endl;
    else
        std::cout << (X * K) + (Y * (N-K)) << std::endl;
}

int main() {
    solve();
    return 0;
}