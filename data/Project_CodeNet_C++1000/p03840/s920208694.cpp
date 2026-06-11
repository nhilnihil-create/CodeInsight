#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a[7];
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }

    long long c1 = a[1] + a[0] / 2 * 2 + a[3] / 2 * 2 + a[4] / 2 * 2;

    long long c2 = a[1];
    if (1 <= a[0] && 1 <= a[3] && 1 <= a[4]) {
        c2 += 3;
        a[0]--;
        a[3]--;
        a[4]--;
    }   
    c2 += a[0] / 2 * 2 + a[3] / 2 * 2 + a[4] / 2 * 2;

    cout << max(c1, c2) << endl;
}