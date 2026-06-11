/**
 *    author:  FromDihPout
 *    created: 2020-06-24
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long x;
    cin >> x;
    
    long long ans = x / 11;
    long long curr = ans * 11;
    if (x == 0) {
        cout << 1 << endl;
    }
    else if (x - curr == 0) {
        cout << ans * 2 << endl;
    }
    else if (x - curr <= 6) {
        cout << ans * 2 + 1 << endl;
    }
    else {
        cout << ans * 2 + 2 << endl;
    }
    return 0;
}