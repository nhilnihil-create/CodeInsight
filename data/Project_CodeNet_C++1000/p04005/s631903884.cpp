#include <iostream>

int main(void){
    long long A, B, C, ans = 0;
    std::cin >> A >> B >> C;

    for (int i = 0; i < 2; ++i){
        if (A > B){
            long long tmp = A;
            A = B;
            B = tmp;
        }
        if (B > C){
            long long tmp = B;
            B = C;
            C = tmp;
        }
    }

    ans = A * B * (C % 2);

    std::cout << ans << std::endl;

    return 0;
}
