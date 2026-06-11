#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL A[123456], kPlus[123456], kTotal[123456];

int main(){
    
    // 1. 入力情報取得.
    int N, K;
    scanf("%d %d", &N, &K);
    LL pTotal = 0;
    for(int i = 0; i < N; i++){
        scanf("%lld", &A[i]);
        if(A[i] > 0) pTotal += A[i];
    }
    
    // 2. プラスのみの累積和, 符号に依らない累積和 を 保存.
    // ex.
    // kPlus[4]  は, A[0] ～ A[4] で, プラスのものだけを合計.
    // kTotal[4] は, A[0] ～ A[4] を合計.
    kPlus[0] = (A[0] > 0) ? A[0] : 0;
    kTotal[0] = A[0];
    for(int i = 1; i < N; i++){
        // kPlus更新.
        if(A[i] > 0) kPlus[i] += kPlus[i - 1] + A[i];
        else         kPlus[i] =  kPlus[i - 1];
        // kTotal更新.
        kTotal[i] += kTotal[i - 1] + A[i];
    }
    // for(int i = 0; i < N; i++) printf("%lld ", kPlus[i]);
    // printf("\n");
    // for(int i = 0; i < N; i++) printf("%lld ", kTotal[i]);
    // printf("\n");
    
    // 3. スコアの最大値を計算.
    LL ans = 0;
    for(int i = K - 1; i < N; i++){
        LL kp = (i > K - 1) ? kPlus[i]  - kPlus[i - K]  : kPlus[i];
        LL kt = (i > K - 1) ? kTotal[i] - kTotal[i - K] : kTotal[i];
        // K個連続で, 黒色にする場合.
        ans = max(ans, pTotal - kp + kt);
        // K個連続で, 白色にする場合.
        ans = max(ans, pTotal - kp + 0);
    }
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}