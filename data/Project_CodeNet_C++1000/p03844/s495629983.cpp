#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    string op;
    
    cin >> A >> op >> B;
    
    cout << (op == "+" ? A + B : A - B ) << endl;

}