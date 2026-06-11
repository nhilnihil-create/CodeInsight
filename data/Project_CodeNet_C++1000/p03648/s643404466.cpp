#include <bits/stdc++.h>

using namespace std;

long long k, a[55], x, y;

int main () {
    cin >> k;
    cout << 50 << "\n";
    x = k / 50;
    x += 49;
    y = k % 50;
    for (int i = 0; i < 50; i++) {
        if (i < y) {
            a[i]+= 51;
            for (int j = 0; j < 50; j++) {
                a[j]--;
            }
        }
        a[i] += x;
        //if (a[i] == 49) a[i] = 0;
    }
    for (int i = 0; i < 50; i++) cout << a[i] << ' ';
    /*if (k % 2 == 0) {
        cout << 2 << "\n" << (1 + k / 2) << " " << (1 + k / 2);
    } else {
        cout << 2 << "\n" << (3 + k / 2) << " " << (k / 2);
    }*/
    return 0;
}
