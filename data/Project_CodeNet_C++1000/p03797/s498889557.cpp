/**
 *    author:  FromDihPout
 *    created: 2020-06-25
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    
    if (n >= m / 2) {
        cout << m / 2 << endl;
    }
    else {
        long long add = (m - 2 * n) / 4;
        cout << n + add << endl;
    }
    return 0;
}