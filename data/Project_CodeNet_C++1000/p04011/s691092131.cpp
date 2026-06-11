#include <iostream>
#include <cstdio>

using namespace std;


class Solution{

public:
    int fee(int N, int K, int X, int Y){

        return N <= K ? N * X : K * X +  (N - K) * Y;
    }
};

int main() {

    int N, K, X, Y;
    scanf("%d%d%d%d", &N, &K, &X, &Y);
    printf("%d\n", Solution().fee(N, K, X, Y));
    
    return 0;
}
