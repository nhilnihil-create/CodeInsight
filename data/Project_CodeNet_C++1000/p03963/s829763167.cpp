#include <iostream>

using namespace std;


class Solution{

public:
    int ways(int N, int K){

        int res = K;
        for(int i = 1; i < N; i ++)
            res *= (K - 1);
        return res;
    }
};

int main() {

    int N, K;
    scanf("%d%d", &N, &K);
    printf("%d\n", Solution().ways(N, K));

    return 0;
}
