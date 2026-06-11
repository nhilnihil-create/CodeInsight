#include <iostream>

#define P 1000000007

using namespace std;

int main(){
    int N;
    int A[100000];
    int T[100000];
    int A_min[100000];
    int T_min[100000];
    int A_max[100000];
    int T_max[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }
    A_min[0] = A[0];
    A_max[0] = A[0];
    for(int i = 1; i < N ;i++){
        if(A[i] > A[i-1]){
            A_min[i] = A[i];
            A_max[i] = A[i];
        }else{
            A_min[i] = 1;
            A_max[i] = A[i];
        }
    }
    T_min[N-1] = T[N-1];
    T_max[N-1] = T[N-1];
    for(int i = N-2; i >= 0 ;i--){
        if(T[i] > T[i+1]){
            T_min[i] = T[i];
            T_max[i] = T[i];
        }else{
            T_min[i] = 1;
            T_max[i] = T[i];
        }
    }
    long ans = 1;
    
    for(int i = 0; i < N; i++){
        ans = (ans*(max(0, min(A_max[i], T_max[i])-max(A_min[i], T_min[i])+1)))%P;
    }
    cout << ans << endl;
}