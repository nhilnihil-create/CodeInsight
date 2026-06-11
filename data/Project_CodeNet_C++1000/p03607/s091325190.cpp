/**
 *    author:  FromDihPout
 *    created: 2020-08-04
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    set<int> seen;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (seen.count(x)) {
            seen.erase(x);
        }
        else {
            seen.insert(x);
        }
    }
    cout << seen.size() << '\n';
    return 0;
}