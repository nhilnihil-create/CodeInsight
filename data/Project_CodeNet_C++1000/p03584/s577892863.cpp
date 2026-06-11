#include <iostream>
#include <vector>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using lli = long long int;

std::vector<int> A, B;

inline bool subset(int a, int b){ // a ⊆ b
    return (a | b) == b;
} 

int main(void){
    // 入力
    int n, k; scanf("%d%d", &n, &k);
    A.resize(n); B.resize(n);
    REP(i, n) scanf("%d%d", &A[i], &B[i]);

    lli ans = 0;
    REP(i, n) if(subset(A[i], k)) ans += B[i];
    // 候補を全探索すればいい(はず)
    int t = 0;
    while((1 << t) <= k){
        lli subAns = 0;
        int tt = 1 << t; t++;
        int koho = (k | (tt - 1)) ^ tt;
        // ビットが立って居ないものはやらない
        if(koho > k) continue;
        
        REP(i, n) if(subset(A[i], koho)) subAns += B[i];
        
        if(ans < subAns) ans = subAns;
    }

    // 出力
    printf("%lld\n", ans);
    return 0;
}