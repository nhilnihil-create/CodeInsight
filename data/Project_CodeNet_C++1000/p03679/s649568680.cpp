/**
 *    author:  FromDihPout
 *    created: 2020-08-01
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, a, b;
    cin >> x >> a >> b;
    
    if (b <= a) {
        cout << "delicious" << '\n';
    }
    else if (b - a <= x) {
        cout << "safe" << '\n';
    }
    else {
        cout << "dangerous" << '\n';
    }
    
    return 0;
}
