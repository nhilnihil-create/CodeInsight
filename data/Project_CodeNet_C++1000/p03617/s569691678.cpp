#include <iostream>
#include <algorithm>

int main(void){
    long long N, Q, H, S, D, min_price, ans=0;
    std::cin >> Q >> H >> S >> D >> N;
    Q *= 4;
    H *= 2;
    min_price = std::min(Q, H);
    min_price = std::min(min_price, S);
    if (N % 2 == 1) ans += min_price;
    ans += N / 2 * std::min(min_price * 2, D);

    std::cout << ans << std::endl;

    return 0;
}
