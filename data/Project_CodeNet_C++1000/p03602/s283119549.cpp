#include<bits/stdc++.h>
using namespace std;

const int MAX = 305;

int A[MAX][MAX], B[MAX][MAX];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            B[i][j] = A[i][j];
        }
    }

    bool flg = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (A[j][k] > A[j][i] + A[i][k]) flg = true;
                if (i != j && i != k && A[j][k] == A[j][i] + A[i][k]) B[j][k] = 0;
            }
        }
    }

    if (flg) printf("-1\n");
    else {
        long long ans = 0ll;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans += B[i][j];
            }
        }
        ans /= 2;
        printf("%lld\n", ans);
    }
    
    return 0;
}