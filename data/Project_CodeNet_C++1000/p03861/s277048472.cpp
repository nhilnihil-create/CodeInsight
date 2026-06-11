/**
 *    author:  FromDihPout
 *    created: 2020-09-11
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long a, b, x;
    cin >> a >> b >> x;
    a = (a + x - 1) / x * x;
    b = b / x * x;
    if (b >= a) {
        cout << (b - a) / x + 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}
