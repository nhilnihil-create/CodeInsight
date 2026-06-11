/**
 *    author:  FromDihPout
 *    created: 2020-06-25
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
    
    set<int> unique;
    for (int i = 0; i < n; i++) {
        unique.insert(a[i]);
    }
    
    int m = (int) unique.size();
    if ((n & 1) && (m & 1)) {
        cout << m << endl;
    }
    else {
        cout << m - 1 << endl;
    }
    return 0;
}