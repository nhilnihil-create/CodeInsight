#include <iostream>

int main(void){
    int N, K, ans=0;
    std::cin >> N >> K;

    for (int i=0; i<N; ++i){
        int x;
        std::cin >> x;
        if (x > abs(x - K)){
            ans += 2 * abs(x - K);
        } else {
            ans += 2 * x;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}