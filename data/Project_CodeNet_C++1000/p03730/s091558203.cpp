#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, m;
    cin >> a >> b >> c;
    m = __gcd(__gcd(a, b), c);
    a /= m;
    b /= m;
    c /= m;
    if (c % __gcd(a, b) == 0) cout << "YES";
    else cout << "NO";
}