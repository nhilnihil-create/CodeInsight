// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    
    // 1. 入力情報.
    LL N, A, B;
    scanf("%lld %lld %lld", &N, &A, &B);
    
    // 2. 総和としてありうる値の個数.
    LL ans = max(0LL, (N - 2) * (B - A) + 1);
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}