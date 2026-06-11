/**
 *    author:  FromDihPout
 *    created: 2020-06-19
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        long long mult = max({(a + x - 1) / x, (b + y - 1) / y, (long long) 1});
        a = mult * x;
        b = mult * y;
    }
    cout << a + b << endl;
    return 0;
}