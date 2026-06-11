#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d <= a || b <= c) {
        cout << 0 << endl;
    }

    else if (a <= d && d <= b && c <= a) {
        cout << d - a << endl;
    }

    else if (a <= c && d <= b) {
        cout << d - c << endl;
    }

    else if (a <= c && c <= b && b <= d) {
        cout << b - c << endl;
    }

    else if (c <= a && a <= b && b <= d) {
        cout << b - a << endl;
    }
}
