#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int AB = A * B, CD = C * D;

    if (AB < CD) {
        cout << CD << endl;
    }
    else {
        cout << AB << endl;
    }
}