#include <bits/stdc++.h>
using namespace std;

int main (){
    string A,op,B;
    cin >> A >> op >> B;
    std::istringstream ss1,ss2;
    ss1 =std::istringstream(A);
    ss2 =std::istringstream(B);
    int a,b;
    ss1 >> a;
    ss2 >> b;
    if (op == "+"){
        cout << a + b << endl;
    }else{
        cout << a - b << endl;
    }
}