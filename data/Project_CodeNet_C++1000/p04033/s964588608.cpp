#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < 0) {
        if (b < 0) {
            if (a == b) {
                cout << "Positive" << endl;
            } else if ((b + a) % 2 == 0) {
                cout << "Negative" << endl;
            } else {
                cout << "Positive" << endl;
            }
        } else {
            cout << "Zero" << endl;
        }
    } else if (a > 0) {
        if (b > 0) {
            cout << "Positive" << endl;
        } else {
            cout << "Zero" << endl;
        }
    } else {
        cout << "Zero" << endl;
    }

    return 0;
}
