#include <iostream>
#include <vector>

int main(void){
    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<char>> A(H + 2, std::vector<char>(W + 2, '#'));

    for (int i=1; i<H+1; ++i){
        for(int j=1; j<W+1; ++j){
            char a;
            std::cin >> a;
            A.at(i).at(j) = a;
        }
    }

    for (int i=0; i<H+2; ++i){
        for (int j=0; j<W+2; ++j){
            std::cout << A.at(i).at(j);
        }
        std::cout << std::endl;
    }

    return 0;
}
