#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int A, B;
    cin >> A >> B;

    bool one = false;
    if ((A == 1) || (B == 1)) {
       one = true;
    }

    if (one) {
        if (A == 1 && B == 1) {
            cout << "Draw" << endl;
        } else if (A == 1) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    if (!one) {
        if (A > B) {
            cout << "Alice" << endl;
        } else if (A < B) {
            cout << "Bob" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }

    return 0;
}