#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int A[50], B[50],C[50],D[50];
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
    for (int i=0; i<M; i++){
        cin >> C[i] >> D[i];
    }
    int x;
    for (int i=0; i<N; i++){
        int min_diff=1000000000;
        for (int j=0; j<M; j++){
            int diff;
            diff=abs(A[i]-C[j])+abs(B[i]-D[j]);
            if (min_diff>diff){
                min_diff=diff;
                x=j+1;
            }
        }
        cout << x << endl;
    }
    return 0;
}