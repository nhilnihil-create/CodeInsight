#include <bits/stdc++.h>
using namespace std;

int N;
int A[110];
int main(){
    cin >> N;
    for(int i=0; i<N; i++) A[i] = i+1;

    
    int res = 0;
    while(true){
        bool exist_even = false;
        for(int i=0; i<N; i++){
            if(A[i] % 2 == 0 && A[i] != 0) exist_even = true;
        }

        if(exist_even){
            for(int i=0; i<N; i++) A[i] /= 2;
            res++;
        }
        else {
            break;
        }

        
    }

    int ans = 1;
    for(int i=0; i<res; i++) ans *= 2;
    cout << ans  << endl;
    
}