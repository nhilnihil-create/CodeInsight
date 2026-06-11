#include <iostream>
#include <algorithm>
#include <vector>

int main(void){
    int N, ans = 0;
    std::cin >> N;
    std::vector<int> A(100002, 0);

    for (int i = 0; i < N; ++i){
        int a;
        std::cin >> a;
        if (a != 0){
            ++A[a - 1];
        }
        ++A[a];
        ++A[a + 1];
    }

    for (int i = 0; i < 100001; ++i){
        ans = std::max(ans, A[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}
