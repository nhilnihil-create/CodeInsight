#include <bits/stdc++.h>

int main() {
    int X, A, B;
    std::cin >> X >> A >> B;

    if ((B - A) <= 0) {
        std::cout << "delicious\n";
    } else if ((B - A) > X) {
        std::cout << "dangerous\n";
    } else {
        std::cout << "safe\n";
    }

    return 0;
}
