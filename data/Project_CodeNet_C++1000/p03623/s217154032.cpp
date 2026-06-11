#include <bits/stdc++.h>
using namespace std;

int main(){

    int x, a, b, A, B;

    cin >> x >> a >> b;

    A = x - a;

    if(A < 0){
        A *= -1;
    }

    B = x - b;

    if(B < 0){
        B *= -1;
    }

    if(A <= B){
        cout << "A" << endl;
    }
    else{
        cout << "B" << endl;
    }

    return 0;

}

