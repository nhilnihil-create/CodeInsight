#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if ( !(c >= a) ) {
        cout << "No";
    }
    else if ( !(b >= c) ) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}
