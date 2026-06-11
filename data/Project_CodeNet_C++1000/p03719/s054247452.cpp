#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << ((A <= C && C <= B) ? "Yes" : "No") << std::endl;

    return 0;
}
