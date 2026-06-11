#include <iostream>
#include <vector>

int main(void){
    int N, mn = 0, mx = 0;
    std::cin >> N;
    std::vector<int> A(9, 0);

    for (int i = 0; i < N; ++i){
        int a;
        std::cin >> a;
        a /= 400;
        if (a > 7) a = 8;
        ++A[a];
    }

    for (int i = 0; i < 8; ++i){
        if (A[i] > 0) ++mn;
    }

    mx += mn + A[8];
    if (mn == 0) ++mn;

    std::cout << mn << " " << mx << std::endl;

    return 0;
}
