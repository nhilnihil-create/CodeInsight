#include <iostream>

int main(void){
    int N, K, ans = 0;
    std::cin >> N >> K;

    ans = K;
    for (int i = 1; i < N; ++i){
        ans *= (K - 1);
    }

    std::cout << ans << std::endl;

    return 0;
}
