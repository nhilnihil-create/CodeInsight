#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long a, b;

    cin >> a >> b;
    if(a == b){
        cout << 0;
    } else if (abs(abs(a) - abs(b)) == 0) {
        cout << 1;
    } else if (a > b) {
        //
        if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) {
            cout << abs(abs(a) - abs(b)) + 1;
        }else{
            cout << abs(abs(a) - abs(b)) + 2;
        }

    } else {
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            cout << abs(abs(a) - abs(b)) + 1;
        } else {
            cout << abs(abs(a) - abs(b));
        }
    }

    //
}
