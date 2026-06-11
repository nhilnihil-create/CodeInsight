#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int square1, square2 = 0;
    square1 = A * B;
    square2 = C * D;

    if (square1 > square2) {
        cout << square1 << endl;
    } else if (square1 < square2)
    {
        cout << square2 << endl;
    } else
    {
        cout << square1 << endl;
    }
    
    return 0;
}