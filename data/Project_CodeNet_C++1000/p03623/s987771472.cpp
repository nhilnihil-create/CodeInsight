/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, a, b;
    cin >> x >> a >> b;
    
    if (abs(a - x) < abs(b - x)) {
        cout << "A";
    }
    else {
        cout << "B";
    }
    return 0;
}