#include <bits/stdc++.h>
using namespace std;

int main(void){
  
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    if(B < D){
        if(C <= A && B <= D) cout << B - A << endl;
        else if(B < C) cout << 0 << endl;
        else cout << B - C << endl;
    }
    else{
        if(A <= C && D <= B) cout << D - C << endl;
        else if(D < A) cout << 0 << endl;
        else cout << D - A << endl;
    }
}