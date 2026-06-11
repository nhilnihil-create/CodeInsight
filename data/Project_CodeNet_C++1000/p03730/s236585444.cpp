#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool ispossible = false;

    for (int i = 1; i < B; i++) {
        if ((A*i - C)%B == 0) {
            ispossible = true;
            break;
        }
    }

    if (ispossible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}