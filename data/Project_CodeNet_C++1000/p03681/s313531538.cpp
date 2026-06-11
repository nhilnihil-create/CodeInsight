/**
 *    author:  FromDihPout
 *    created: 2020-07-29
**/

#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }
    if (n - m >= 2) {
        cout << 0 << '\n';
        return 0;
    }
    
    long long ans = 1;
    int dec = 0;
    for (int i = 0; i < n + m; i++) {
        if (i % 2 == 0) {
            ans *= n - dec;
        }
        else {
            ans *= m - dec;
            dec++;
        }
        ans %= MOD;
    }
    
    if (n == m) {
        cout << (2 * ans) % MOD << '\n';
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}