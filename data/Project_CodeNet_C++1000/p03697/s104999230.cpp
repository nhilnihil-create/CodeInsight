#include <bits/stdc++.h>

int main() {
    int A, B;
    std::cin >> A >> B;
   
    const int sum = A + B;
    if (sum >= 10) {
        std::cout << "error\n";
    } else {
        std::cout << sum << std::endl;
    }

    return 0;
}
