/**
 *    author:  FromDihPout
 *    created: 2020-08-01
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
        a[i]--;
    }
    
    vector<bool> seen(n);
    int curr = 0, cnt = 0;
    while (curr != 1 && !seen[curr]) {
        seen[curr] = true;
        curr = a[curr];
        cnt++;
    }
    
    if (curr == 1) {
        cout << cnt << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}