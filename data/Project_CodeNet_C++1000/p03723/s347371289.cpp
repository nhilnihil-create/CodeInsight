#include <bits/stdc++.h>

int main() {
    int64_t A, B, C;
    std::cin >> A >> B >> C;

    int ans = 0;
    while (true) {
        if (A % 2 != 0 || B % 2 != 0 || C % 2 != 0) {
            std::cout << ans << std::endl;
            return 0;
        }

        const int a = B / 2 + C / 2; 
        const int b = C / 2 + A / 2; 
        const int c = A / 2 + B / 2; 
        ++ans;

        if (a == A && b == B && c == C) {
            std::cout << -1 << std::endl;
            return 0;
        }

        A = a;
        B = b;
        C = c;
    }


    return 0;
}
