#include <iostream>
#include <vector>

int main(void){
    int N, M, sum_T=0;
    std::cin >> N;
    std::vector<int> T(N);
    for (int i=0; i<N; ++i){
        std::cin >> T.at(i);
        sum_T += T.at(i);
    }

    std::cin >> M;

    for (int i=0; i<M; ++i){
        int p, x;
        std::cin >> p >> x;
        std::cout << sum_T - T.at(p - 1) + x << std::endl;
    }

    return 0;
}
