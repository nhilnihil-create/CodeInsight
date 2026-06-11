#include <iostream>

int main() {
    long long int n;
    std::cin >> n;

    long long exclude = -1, last = 1;
    for (long long i = 1; i <= n; i++) {
        long long t = i * (i + 1) / 2;
        if (t > n) {
            exclude = t - n;
            last = i;
            break;
        }
    }

    for (long long i = 1; i <= last; i++) {
        if (i != exclude) std::cout << i << std::endl;
    }

    return 0;
}