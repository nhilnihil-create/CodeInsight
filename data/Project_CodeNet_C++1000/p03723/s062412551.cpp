#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void){
    
    long long A,B,C;
    
    cin >> A >> B >> C;
    
    long long X,Y,Z;
    long long L,M,N;
    long long count;
    
    count = 0;
    
    L = A;
    M = B;
    N = C;
    if(A%2 == 1 || B%2 ==1 || C%2 ==1){
        cout << 0 << endl;
        return 0;
    }
    if(A == B && B == C && C == A){
        cout << -1 << endl;
        return 0;
    }
    
    while(true){
        
        X = A;
        Y = B;
        Z = C;
        
        A =     + Y/2 + Z/2;
        B = X/2       + Z/2;
        C = X/2 + Y/2      ;

        count++;
        if(count > 100)break;
        if(A%2 == 1 || B%2 ==1 || C%2 ==1)break;
        if(L == A && M == B && N == C){
            count = -1;
            break;
        }
        
    }

    cout << count << endl;
    
}
