#include<iostream>
using namespace std;
int main(){
    int N;
    int A[300][300];
    bool flag;
    long long ans = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(A[i][j] != A[j][i]){
                cout << -1 << endl;
                return 0;
            }
            flag = true;
            for(int k=0;k<N;k++){
                if(k == i||k == j) continue;
                if(A[i][j] > A[i][k] + A[k][j]){
                    cout << -1 << endl;
                    return 0;
                }
                if(A[i][j] == A[i][k] + A[k][j]) flag = false;
            }
            if(flag) ans += A[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
