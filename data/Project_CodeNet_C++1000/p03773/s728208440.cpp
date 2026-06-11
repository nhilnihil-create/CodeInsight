#include <bits/stdc++.h>

int main() {
    int A, B;
    std::cin >> A >> B;

    int C = A + B;
    if (C >= 24) {
        C %= 24;
    }

    std::cout << C << std::endl;

    return 0;
}
