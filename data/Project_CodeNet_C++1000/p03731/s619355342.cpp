/**
 *    author:  FromDihPout
 *    created: 2020-07-26
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] + t < a[i]) {
            ans += t;
        }
        else {
            ans += a[i] - a[i-1];
        }
    }
    ans += t;
    cout << ans << '\n';
    return 0;
}