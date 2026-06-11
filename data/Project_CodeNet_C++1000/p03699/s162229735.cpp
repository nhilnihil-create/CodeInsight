/**
 *    author:  FromDihPout
 *    created: 2020-07-29
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum % 10 != 0) {
        cout << sum << '\n';
    }
    else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if ((sum - a[i]) % 10 != 0) {
                ans = max(ans, sum - a[i]);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}