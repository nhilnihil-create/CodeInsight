#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;

        if (K - x < x) {
            count += (K - x) * 2;
        } else {
            count += x * 2;
        }
    }

    std::cout << count << std::endl;

    return 0;
}