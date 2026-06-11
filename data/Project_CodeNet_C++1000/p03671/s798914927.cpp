#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c, A, B, C;

    cin >> a >> b >> c;

    A = a + b;
    B = b + c;
    C = c + a;

    if(A <= B && A <= C){
        cout << A << endl;
    }
    else if(B <= A && B <= C){
        cout << B << endl;
    }
    else if(C <= A && C <= B){
        cout << C << endl;
    }

    return 0;

}

