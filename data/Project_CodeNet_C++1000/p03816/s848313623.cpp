#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = (a), i_len = (b); i < i_len; ++i)

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    REP(i, 0, N) scanf("%d", &A[i]);

    sort(A, A + N);
    int B[N], len = 0;
    {
        int cur = 0;
        int p = A[0];
        B[cur] = 0;
        REP(i, 0, N) {
            if(A[i] == p) ++B[cur];
            else { ++cur; p = A[i]; B[cur] = 1; }
        }
        len = cur + 1;
    }

    /*
    REP(i, 0, N) printf("%d ", A[i]);
    printf("\n");
    REP(i, 0, len) printf("%d ", B[i]);
    printf("\n");
    */
    int sm = 0;
    REP(i, 0, len) if(B[i] > 1) sm += B[i] - 1;
    if(sm%2 != 0) sm += 1;
    printf("%d\n", N - sm);
    return 0;
}