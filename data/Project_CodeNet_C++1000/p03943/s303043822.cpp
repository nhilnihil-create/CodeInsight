#include <iostream>
using namespace std;

int main (void) {
    int a, b, c;

    cin >> a >> b >> c;

    if (a == b + c) {
        cout << "Yes" << endl;
    }
    else if (b == c + a) {
        cout << "Yes" << endl;
    }
    else if (c == a + b){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;

}