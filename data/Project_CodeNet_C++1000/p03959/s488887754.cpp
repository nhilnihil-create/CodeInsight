#include <stdio.h>
#include <vector>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define END(ans) {ans = 0; break;}

using lli = long long int;

constexpr int mod = 1e9 + 7;
std::vector<int> A, B;
std::vector<bool> P, Q;


int main(void){
    int n; scanf("%d", &n);
    A.resize(n); REP(i, n) scanf("%d", &A[i]);
    B.resize(n); REP(i, n) scanf("%d", &B[i]);
    P.resize(n, false); FOR(i, 1, n) if(A[i-1] < A[i]) P[i] = true; P[0] = true;
    Q.resize(n, false); FOR(i, 1, n) if(B[i-1] > B[i]) Q[i-1] = true; Q[n-1] = true;
    lli res = 1;
    REP(i, n){
        if(P[i]){if(A[i] > B[i]) END(res)}
        else if(Q[i]){if(B[i] > A[i]) END(res) }
        else (res *= (A[i] > B[i]) ? B[i] : A[i]) %= mod;
    }
    printf("%lld\n", res);  
    return 0;
}