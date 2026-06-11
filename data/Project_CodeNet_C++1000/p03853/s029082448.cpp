#include <iostream>

int main(void){
    int H, W;
    std::cin >> H >> W;

    for (int i=0; i<H; ++i){
        std::string S;
        std::cin >> S;
        std::cout << S << std::endl << S << std::endl;
    }

    return 0;
}
