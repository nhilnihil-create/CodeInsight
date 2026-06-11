#include <bits/stdc++.h>
using namespace std;

bool chk[333][333];
int A[333][333];

int main() {
    int N; scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&A[i][j]);
        }
    }
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(A[i][k] + A[k][j] < A[i][j]) return !printf("-1");
                if(i != k && k != j && A[i][k] + A[k][j] == A[i][j]) chk[i][j] = 1;
            }
        }
    }
    long long ans = 0;
    for(int i=1; i<=N; i++) {
        for(int j=i+1; j<=N; j++) {
            if(!chk[i][j]) ans += A[i][j];
        }
    }
    printf("%lld", ans);
    return 0;
}
