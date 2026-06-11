#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    long long N,A,B;
    cin >> N >> A >> B;
    
    if(A>B){
        cout << 0 << endl;
        return 0;
    }
    if(N==1){
        if(A==B)cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    long long mn = B;
    long long mx = A;
    for(int i = 0; i < N-1;i++){
        
        mx += B;
        mn += A;
    }
    
    //cout << mx <<" "<<mn <<endl;
    cout << (mx-mn+1) <<endl;
}

    
    

