#include <iostream>

int main() {
    int n, m, k; std::cin >> n >> m >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (((n-i)*j + (m-j)*i) == k) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}
