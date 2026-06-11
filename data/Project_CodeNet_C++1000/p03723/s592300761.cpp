#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int count = 0;
    while (true) {
        if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1)
            break;
        if (A == B && A == C) {
            std::cout << -1 << std::endl;
            return 0;
        }

        count++;

        int a, b, c;
        a = B / 2 + C / 2;
        b = C / 2 + A / 2;
        c = A / 2 + B / 2;
        A = a;
        B = b;
        C = c;
    }

    std::cout << count << std::endl;

    return 0;
}