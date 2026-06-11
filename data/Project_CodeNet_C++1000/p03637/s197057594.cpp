#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int four = 0, two = 0, others = 0, A;
    for (int i = 0; i < N; ++i) {
        std::cin >> A;
        if (A % 4 == 0) {
            ++four;
        } else if (A % 2 == 0) {
            ++two;
        } else {
            ++others;
        } 
    }

    if (four >= (others + two % 2 - 1)) {
        std::cout << "Yes\n"; 
    } else {
        std::cout << "No\n";
    }

    return 0;
}
