#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, A, B;
    cin >> X >> A >> B;
    int a, b;

    if(X < B){
        b = B - X;
    }
    else if(X > B){
        b = X - B;
    }

    if(X < A){
        a = A - X;
    }
    else if(X > A){
        a = X - A;
    }

    if(a > b){
        cout << 'B' << endl;
    }
    else{
        cout << 'A' << endl;
    }
}