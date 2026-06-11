#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a<=c && d<=b) cout << d-c << endl;
    else if (c<=a && b<=d) cout << b-a << endl;
    else if (a < c) {
        if (c < b) cout << b - c << endl;
        else cout << 0 << endl;
    }
    else if (c < a) {
        if (a < d) cout << d - a << endl;
        else cout << 0 << endl;
    }
}