/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long lcm = 1;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long gcd = __gcd(x, lcm);
        lcm = x / gcd * lcm;
    }
    cout << lcm << '\n';
    return 0;
}