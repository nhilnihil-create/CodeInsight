#include <bits/stdc++.h>

using namespace std;

#define MAX 300
int A[MAX][MAX];
bool edge[MAX][MAX];

int main(){
    int N, i, j, k;
    long long ans = 0;
    cin >> N;
    for(i = 0; i < N; i++) 
        for(j = 0; j < N; j++) {
            cin >> A[i][j];
            edge[i][j] = true;
            ans += A[i][j];
    }

    for(k = 0; k < N; k++) {
        for(j = 0; j < N; j++) {
            for(i = 0; i < N; i++){
                if(A[i][j] > A[i][k] + A[k][j]) {
                    return !printf("-1\n");
                }
                else if(A[i][j] == A[i][k] + A[k][j]) {
                    if(k != i && k != j && edge[i][j]) {
                        ans -= A[i][j];
                        edge[i][j] = false;
                    }
                }
            }
        }
    }

    return !printf("%lld\n", ans/2);
}