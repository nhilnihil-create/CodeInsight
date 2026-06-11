#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) {
        cout << "Positive" << endl;
    }
    else if (a < 0 && b < 0) {
        int cnt = abs(a) - abs(b) + 1;
        if (cnt % 2 == 0) {
            cout << "Positive" << endl;
        }
        else {
            cout << "Negative" << endl;
        }
    }
    else {
        cout << "Zero" << endl;
    }
    return 0;
}