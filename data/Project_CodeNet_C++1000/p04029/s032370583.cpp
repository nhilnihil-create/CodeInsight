/// Source : https://atcoder.jp/contests/abc043/tasks/abc043_a
/// Author : liuyubobobo
/// Time   : 2020-09-22

#include <iostream>
#include <cstdio>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution{

public:
    int candy(int N){
        return (1 + N) * N / 2;
    }
};

int main() {

    int N;
    scanf("%d", &N);
    printf("%d\n", Solution().candy(N));
    return 0;
}
