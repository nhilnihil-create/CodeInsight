#include <iostream>

int main() {
    int N; std::cin >> N;
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        ret += (r - l + 1);
    }

    std::cout << ret << std::endl;
    return 0;
}