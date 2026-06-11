#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b && b <= c && c <= d) cout << '0';
    else if (a <= c && c <= b && b <= d) cout << b - c;
    else if (a <= c && c <= d && d <= b) cout << d - c;
    else if (c <= a && a <= b && b <= d) cout << b - a;
    else if (c <= a && a <= d && d <= b) cout << d - a;
    else if (c <= d && d <= a && a <= b) cout << '0';
}
