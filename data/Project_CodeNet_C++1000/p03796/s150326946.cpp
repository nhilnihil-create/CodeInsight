#include <iostream>

int main(void){
    long long N, ans=1, mod=1e9+7;
    std::cin >> N;

    for (int i = 1; i <= N; ++i){
        ans = ans * i % mod;
    }

    std::cout << ans << std::endl;

    return 0;
}
