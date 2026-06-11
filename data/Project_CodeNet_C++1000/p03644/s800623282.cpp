#include <iostream>

int main(void){
    int N, ans=1;
    std::cin >> N;

    for (int i = 1; i<7; ++i){
        if (ans * 2 <= N){
            ans *= 2;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}