#include <iostream>
#include <cstdio>

int main() {
    int N;
    std::cin >> N;

    int k = 1;
    for ( ; ; ++k)
        if (k * (k+1) >= 2*N)
            break;
    int rem = k * (k + 1) / 2 - N;
    for (int i = 1; i <= k; ++i)
        if (rem != i)
            printf("%d\n", i);

    return 0;
}
