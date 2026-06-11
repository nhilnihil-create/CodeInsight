#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B;
    cin >> A >> B;
    if(A + B < 24){
        cout << A + B << endl;
    }else{
        cout << abs(24 - (A+B)) << endl;
    }
}
