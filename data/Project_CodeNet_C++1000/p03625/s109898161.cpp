#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    long long h,w;
    h = w = 0;
    for(int i = 1; i < N; i++){
        if(A[i] == A[i-1]){
            h = A[i];
            A[i] = -1;
            A[i-1] = -2;
            break;
        } 
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    for(int i = 1; i < N; i++){
        if(A[i] == A[i-1]){
            w = A[i];
            break;
        }
    }
    cout << h * w << endl;
}
