#include <bits/stdc++.h>

#define lint long long

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<lint> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    sort(A.begin(), A.end(), greater<lint>());
    
    lint longest = 0;
    
    for(int i = 0; i < N - 1; ++i){
        if(A[i] == A[i + 1]){
            if(longest == 0){
                longest = A[i];
                i++;
            } else {
                cout << longest * A[i] << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    
}