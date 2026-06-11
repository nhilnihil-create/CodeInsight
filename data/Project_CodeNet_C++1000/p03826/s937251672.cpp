#include <iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int A=a*b, B=c*d;

    if(A>=B){
        cout << A << endl;
    } else {
        cout << B << endl;
    }

    return 0;
}