#include <stdio.h>
#include <algorithm>

template <class S, class T> void chmax(S& lhs, const T& rhs){ if(lhs < rhs) lhs = rhs; }

constexpr unsigned int MAX_N = 100'000; // '
constexpr unsigned int MAX_M = 100'000; // '
unsigned int A[MAX_N];
long long int P[2 * MAX_M + 1];
long long int Q[2 * MAX_M + 1];

int main(void){
    unsigned int n, m; scanf("%u%u", &n, &m);
    for(unsigned int i = 0; i < n; ++i){ scanf("%u", A + i); --A[i]; }

    long long int S = 0;
    for(unsigned int i = 0; i + 1 < n; ++i){
        unsigned int l, r, L;
        if(A[i] < A[i + 1]){l = A[i]; r = A[i + 1]; L = r - l; }
        else{ l = A[i]; r = A[i + 1] + m; L = r - l; }
        S += L;
        if(L <= 1) continue;
        ++P[l + 2]; --P[r + 1]; Q[r + 1] -= L - 1;
    }
    {
        const unsigned int M = m << 1;
        for(unsigned int i = 1; i <= M; ++i) P[i] += P[i - 1];
        for(unsigned int i = 0; i <= M; ++i) P[i] += Q[i];
        for(unsigned int i = 1; i <= M; ++i) P[i] += P[i - 1];
    }
    long long int mx = 0;
    for(unsigned int i = 0; i < m; ++i) chmax(mx, P[i] + P[i + m]);
    printf("%lld\n", S - mx);
    return 0;
}