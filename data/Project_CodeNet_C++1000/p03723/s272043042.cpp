#include "bits/stdc++.h"

using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c;

    if (a & 1 || b & 1 || c & 1)
        cout << 0 << endl;

    else if (a == b && b == c)
        cout << -1 << endl;

    else {
        int ans = 0;
        while (true) {
            if (a & 1 || b & 1 || c & 1)
                break;
            x = a;
            y = b;
            z = c;
            a = (y + z) / 2;
            b = (z + x) / 2;
            c = (x + y) / 2;
            ans += 1;
        }
        cout << ans << endl;
    }
}
