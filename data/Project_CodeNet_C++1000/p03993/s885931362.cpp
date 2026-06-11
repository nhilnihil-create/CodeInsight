#include <iostream>
#include <vector>

int main(void){
    int N, ans = 0;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i){
        std::cin >> A[i];
        --A[i];
    }

    for (int i = 0; i < N; ++i){
        if (i == A[A[i]]) ++ans;
    }

    std::cout << ans / 2 << std::endl;

    return 0;
}
