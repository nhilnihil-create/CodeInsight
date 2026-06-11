#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    for (int x = 1;; ++x) {
        if (x * (x + 1) / 2 >= X) {
            cout << x << endl;
            return 0;
        }
    }
}