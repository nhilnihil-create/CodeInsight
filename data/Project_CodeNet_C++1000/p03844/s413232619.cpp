#include <iostream>
#include <string>
using namespace std;

int main(){
    long long A, B;
    string op;

    cin >> A >> op >> B;

    if(op == "+"){
        cout << A+B << endl;
    }else{
        cout << A-B << endl;
    }
}