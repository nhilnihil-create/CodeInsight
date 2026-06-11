#include<iostream>
#include<cstdio>
using namespace std;


long long N, A[300][300];
bool useless[300][300];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    bool error = false;
    long long ans = 0;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(A[i][j] > A[i][k] + A[k][j]){
                    error = true;
                }
                if(k != i && k != j && A[i][j] == A[i][k] + A[k][j]){
                    useless[i][j] = true;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(!useless[i][j]){
                ans += A[i][j];
            }
        }
    }
    if(error){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}
                