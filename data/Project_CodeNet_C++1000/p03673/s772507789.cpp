/**
 *    author:  FromDihPout
 *    created: 2020-07-31
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int start = n / 2, dist = 0;
    vector<int> ans(n);
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans[start + dist] = a[i];
                dist++;
            }
            else {
                ans[start - dist] = a[i];
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans[start - dist] = a[i];
                dist++;
            }
            else {
                ans[start + dist] = a[i];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
