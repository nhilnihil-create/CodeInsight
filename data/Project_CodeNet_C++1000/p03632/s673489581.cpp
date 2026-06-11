#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, res, upper, lower;
    cin >> A >> B >> C >> D;

    if (A > C) {
        lower = A;
    } else {
        lower = C;
    }

    if (B > D) {
        upper = D;
    } else {
        upper = B;
    }

    res = upper - lower;

    if (res < 0) res = 0; 

    cout << res << endl;
}