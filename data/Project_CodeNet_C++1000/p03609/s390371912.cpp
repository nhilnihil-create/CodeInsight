#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, t, r;
    cin >> x >> t;
    r = x - t;
    if (r < 0) {
        cout << 0 << '\n';
    } else {
        cout << r << '\n';
    }
}