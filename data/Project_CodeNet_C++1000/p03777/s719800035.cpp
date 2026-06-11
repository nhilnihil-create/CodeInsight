#include <bits/stdc++.h>
using namespace std;

int main() {
    char A,B;
    cin >> A >> B;
    if ((A == 'H' && B == 'H')||(A == 'D' && B == 'D')) {
        cout << 'H' << endl;
    }
    else {
        cout << 'D' << endl;
    }
}

