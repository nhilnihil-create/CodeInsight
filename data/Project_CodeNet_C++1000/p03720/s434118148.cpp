#include <iostream>
#include <vector>

int main(void){
    int N, M;
    std::cin >> N >> M;
    std::vector<int> roads(N, 0);
    for (int i=0; i<M; ++i){
        int a, b;
        std::cin >> a >> b;
        ++roads.at(a - 1);
        ++roads.at(b - 1);
    }
        
    for (int i=0; i<N; ++i){
        std::cout << roads.at(i) << std::endl;
    }

    return 0;
}
