#include <bits/stdc++.h>
using namespace std;

int main() {
    int X,A,B;
    cin >> X >> A >> B;

    if(A>=B){
        cout << "delicious";
    }else{
        int after = B-A;
        if(after <= X){
            cout << "safe";
        }else{
            cout << "dangerous";
        }
    }
    return 0;
}