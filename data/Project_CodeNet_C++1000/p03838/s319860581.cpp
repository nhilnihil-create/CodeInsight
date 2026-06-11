#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    if (x == abs(y)) {
        cout << 1 << endl;
    } else {
        int count = 0;
        if (abs(x) > abs(y)) {
            if (x > 0) {
                x = x * -1;
                count += 1;
            }

            while (abs(x) != abs(y)) {
                x += 1;
                count += 1;
            }

            if (x != y) {
                count += 1;
            }
            cout << count << endl;
        } else {
            int count = 0;
            if (0 > x) {
                x = x * -1;
                count += 1;
            }

            while (abs(x) != abs(y)) {
                x += 1;
                count += 1;
            }

            if (x != y) {
                count += 1;
            }
            cout << count << endl;
        }
    }
    return 0;
}