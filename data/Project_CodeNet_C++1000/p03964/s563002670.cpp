#include <bits/stdc++.h>

int main() {
    uint64_t N;
    std::cin >> N;

    uint64_t t = 1, a = 1;
    uint64_t T, A;
    for (size_t i = 0; i < N; ++i) {
        std::cin >> T >> A;

        uint64_t nt = 0;
        if (t % T == 0) {  
            nt = t / T;
        } else {
            nt = t / T + 1;
        }
        
        uint64_t na = 0;
        if (a % A == 0) {  
            na = a / A;
        } else {
            na = a / A + 1;
        }

        const uint64_t n = std::max<uint64_t>(nt, na);

        t = T * n;
        a = A * n;
    }

    std::cout << t + a << std::endl; 

    return 0;
}
