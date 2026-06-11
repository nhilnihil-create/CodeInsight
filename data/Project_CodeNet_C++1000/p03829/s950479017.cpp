/**
 *    author:  FromDihPout
 *    created: 2020-06-24
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long w, t;
    cin >> n >> w >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if ((a[i] - a[i - 1]) * w < t) {
            ans += (a[i] - a[i - 1]) * w;
        }
        else {
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}