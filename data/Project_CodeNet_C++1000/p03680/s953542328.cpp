#include <iostream>
#include <vector>

int main(void){
    int N, tmp = 0, ans = -1;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i){
        std::cin >> A[i];
        --A[i];
    }

    for (int i = 0; i < N; ++i){
        tmp = A.at(tmp);
        if (tmp == 1){
            ans = i + 1;
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
