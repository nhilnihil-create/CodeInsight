#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int X,A,B;
    cin >> X >> A >> B;
    if(A >= B){
        cout << "delicious" << endl;
    }
    else {
        if((B-A) <= X){
            cout << "safe" << endl;
        }
        else cout << "dangerous" << endl;
    }
}