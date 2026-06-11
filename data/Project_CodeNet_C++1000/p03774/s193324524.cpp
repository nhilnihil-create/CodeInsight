#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int A[50], B[50], C[50], D[50];

    for(int i=0;i<N;++i){
        cin >> A[i] >> B[i];
    }

    for(int j=0;j<M;j++){
        cin >> C[j] >> D[j];
    }

    for(int i=0;i<N;++i){
        int min=abs(A[i]-C[0])+abs(B[i]-D[0]);
        int checkpoint=1;

        for(int j=1;j<M;++j){
            int tmp=abs(A[i]-C[j])+abs(B[i]-D[j]);
            if(min>tmp){
                min=tmp;
                checkpoint=j+1;
            }
        }
        cout << checkpoint << endl;
    }
}