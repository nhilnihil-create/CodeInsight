#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long N,M;
    std::cin >> N >> M;
    if(N>M/2){
        std::cout << M/2 << std::endl;
    }else{
        std::cout << N+(M-2*N)/4 << std::endl;
    }
    return 0;
}