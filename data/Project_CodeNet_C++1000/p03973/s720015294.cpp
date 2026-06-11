#include <bits/stdc++.h>

using namespace std;
#define lint long long

int main() {
    int N;
    cin >> N;
    
    lint A[N];
    
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    lint cnt = A[0] - 1;
    A[0] = 1;
    
    lint P = 2;
  
    
    for(int i = 1; i < N; ++i){
        if(A[i] > P){
            lint num = (A[i] - 1) / P;
//            cout << num << " " << P << " ";
            cnt += num;
            if(A[i] % P == 0 && num >= 1){
                A[i] -= P * num + 1;
            } else {
                A[i] -= P * num;
            }
//            cout << A[i] << endl;
        }
        if(A[i] == P){
            ++P;
        }
        
    }
    cout << cnt << endl;
}
