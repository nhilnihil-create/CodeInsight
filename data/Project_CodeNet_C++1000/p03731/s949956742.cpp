#include <iostream>

int main() {
    int n, T; std::cin >> n >> T;
    unsigned long long X = 0;

    int head = 0, tail = 0;

    for (int i = 0; i < n; i++) {
        int t; std::cin >> t;
        if (t <= tail) {
            tail = t + T;
        } else {
            X += tail - head;
            head = t;
            tail = t + T;
        }
    }
    X += tail - head;

    std::cout << X << std::endl;
    return 0;
}