#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int A[200009];

int main() {
    int N; scanf("%d",&N);
    for(int i=1; i<=2*N-1; i++) scanf("%d",&A[i]);
    int l = 1, r = 2*N-1;
    while(l <= r) {
        int m = l+r >> 1;
        int xl = INF, yl = INF;
        for(int i=N; i>=2; i--) {
            if(A[i] <= m && A[i-1] <= m) xl = N-i;
            if(A[i] > m && A[i-1] > m) xl = N-i;
            if(xl != INF) break;
        }
        for(int i=N; i<=2*N-2; i++) {
            if(A[i] <= m && A[i+1] <= m) yl = i-N;
            if(A[i] > m && A[i+1] > m) yl = i-N;
            if(yl != INF) break;
        }
        char res;
        if(min(xl, yl) == INF) {
            if((A[N] <= m) ^ (N%2)) res = 'U';
            else res = 'D';
        }
        else if(xl < yl) {
            if(A[N-xl] <= m) res = 'D';
            else res = 'U';
        }
        else {
            if(A[N+yl] <= m) res = 'D';
            else res = 'U';
        }
        if(res == 'D') r = m-1;
        else l = m+1;
    }
    printf("%d", r+1);
    return 0;
}