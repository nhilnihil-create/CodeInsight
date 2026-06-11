#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) {
        cout << "Positive" << endl;
    } else if (a <= 0 && b > 0) {
        cout << "Zero" << endl;
    } else {
        int64_t sa = abs(a - b);
        if (sa % 2 == 0) {
            cout << "Negative" << endl;
        } else {
            cout << "Positive" << endl;
        }
    }
    return 0;
}