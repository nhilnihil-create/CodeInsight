#include <stdio.h>
#include <vector>
#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
using lli = long long int;
std::vector<lli> A, pS, S;

int main(void){
    int n, k; scanf("%d%d", &n, &k);
    A.resize(n); REP(i, n) scanf("%lld", &A[i]);
    pS.resize(n+1); pS[0] = 0; REP(i, n) pS[i+1] = (A[i] > 0) ? pS[i] + A[i] : pS[i];
    S.resize(n+1); S[0] = 0; REP(i, n) S[i+1] = S[i] + A[i];
    lli res = 0;
    // [0, x) and [x,x+k) and [x+k, n)
    for(int x = 0; x + k <= n; ++x){
        lli p = pS[x] + pS[n] - pS[x+k];
        lli q = S[x+k] - S[x]; if(q < 0) q = 0;
        if(res < p + q) res = p + q;
    }
    printf("%lld\n", res);
    return 0;
}