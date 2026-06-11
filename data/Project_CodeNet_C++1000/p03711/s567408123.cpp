#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B;
    int a,b;
    cin >> A >> B;
    if (A == 2) {
        a = 0;
    }
    else if (A == 4 || A == 6 || A == 9 || A == 11) {
        a = 1;
    }
    else {
        a = 2;
    }
    
    if (B == 2) {
        b = 0;
    }
    else if (B == 4 || B == 6 || B == 9 || B == 11) {
        b = 1;
    }
    else {
        b = 2;
    }

    if (a == b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}
