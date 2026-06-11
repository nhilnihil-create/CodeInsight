#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N;
    long long ans=0;
    std::cin >> N;
    std::vector<long long> A(3 * N);

    for (int i=0; i<3 * N; ++i){
        std::cin >> A.at(i);
    }

    std::sort(A.begin(), A.end());

    for (int i=3*N-2; i>N-1; i-=2){
        ans += A.at(i);
    }

    std::cout << ans << std::endl;

    return 0;
}
