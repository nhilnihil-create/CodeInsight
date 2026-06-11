#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, L;
    std::cin >> N >> L;
    std::vector<std::string> S(N);
    for (int i=0; i<N; ++i){
        std::cin >> S.at(i);
    }
    
    std::sort(S.begin(), S.end());

    for (std::string s: S){
        std::cout << s;
    }

    std::cout << std::endl;

    return 0;
}
