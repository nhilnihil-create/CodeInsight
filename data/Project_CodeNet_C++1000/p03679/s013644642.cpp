#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    int Y = C - B;
    if (Y <= 0) {
        cout << "delicious" << endl;
    }
    else if (Y > A) {
        cout << "dangerous" << endl;
    }
    else {
        cout << "safe" << endl;
    }
}

