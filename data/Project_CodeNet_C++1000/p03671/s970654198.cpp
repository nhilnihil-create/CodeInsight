#include <iostream>

int main() {
    int v[3];
    int max{0};
    int sum{0};
    for (int i = 0; i < 3; ++i) {
        std::cin >> v[i];
        sum += v[i];
        if (max <= v[i]) max = v[i];
    }
    std::cout << (sum - max) << std::endl;

    return 0;
}
