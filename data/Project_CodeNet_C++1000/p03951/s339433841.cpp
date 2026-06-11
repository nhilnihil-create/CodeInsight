#include <iostream>

int main() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    for (int i = 0; i <= n; i++) {
        int j = 0;
        for (j = 0; j < n - i; j++) {
            if (s[j+i] != t[j]) {
                break;
            }
        }
        if (j >= n - i) {
            std::cout << (n - i) + i * 2 << std::endl;
            return 0;
        }
    }
    return 0;
}