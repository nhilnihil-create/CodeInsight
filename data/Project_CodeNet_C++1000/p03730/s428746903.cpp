#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
    int a, b, c;
    a = max(m, n);
    b = min(m, n);
    c = a%b;
    while (c > 1) {
        a = b;
        b = c;
        c = a%b;
    }
    if (c == 1) return 1;
    else return b;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c % gcd(a, b) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}