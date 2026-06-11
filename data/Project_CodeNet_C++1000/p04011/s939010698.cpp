#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int N, K, X, Y;
    scanf("%d %d %d %d", &N, &K, &X, &Y);
    
    // 2. 出力.
    printf("%d\n", min(N, K) * X + max(0, N - K) * Y);
    return 0;
    
}