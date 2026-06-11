#include <bits/stdc++.h>

using namespace std;

int main(){

    int X, A, B;

    cin >> X >> A >> B;

    if(X+A+1 > B && (A+1)-B < 0){
        cout << "safe" << endl;
    }
    else if(X+A+1 > B && (A+1)-B >= 0){
        cout << "delicious" << endl;
    }
    else{
        cout << "dangerous" << endl;
    }

    return 0;

}
