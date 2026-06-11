#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define RREP(i, a, b) for(int i = (a); i >= (b); --i)
int L[5010][5010], R[5010][5010];
int a[5010];

int main() {
    int N; int K;
    scanf("%d %d", &N, &K);
    
    REP(i, 1, N + 1) scanf("%i", &a[i]);

    L[0][0] = 1;
    REP(i, 0, N) REP(j, 0, K) if(L[i][j]) {
        L[i+1][j] = 1;
        if(j + a[i+1] < K) L[i+1][j + a[i+1]] = 1;
    }

    R[N+1][0] = 1;
    RREP(i, N, 1) REP(j, 0, K) if(R[i+1][j]) {
        R[i][j] = 1;
        if(j + a[i] < K) R[i][j + a[i]] = 1;
    }

    REP(i, 0, N + 2) {
        REP(j, 1, K) R[i][j] += R[i][j-1];
    }

    int ans = 0;
    REP(i, 1, N + 1) {
        if(K <= a[i]) continue;

        bool ok = true;
        REP(j, 0, K) if(L[i-1][j]) {
            int lo = max(K - j - a[i], 0);
            int hi = min(K-1, K - j - 1);

            int sm = R[i+1][hi];
            if(0 < lo) sm -= R[i+1][lo-1];
            if(sm != 0) ok = false;
        }
        if(ok) ans++;
    }

    printf("%d\n", ans);
    return 0;
}