#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * b > c * d || a * b == c * d) {
        cout << a * b;
    } else {
        cout << c * d;
    }
}