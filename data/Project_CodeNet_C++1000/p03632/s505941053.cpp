#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int start, end, res;

    if (A < C) {
        start = C;
    } else {
        start = A;
    }

    if (B < D) {
        end = B;
    } else {
        end = D;
    }

    res = end - start;

    if (res < 0) res = 0;

    cout << res << endl;

    return 0;
}
