#include <bits/stdc++.h>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (C >= A && C <= B) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}
