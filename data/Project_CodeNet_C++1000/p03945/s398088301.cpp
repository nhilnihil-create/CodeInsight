/**
 *    author:  FromDihPout
 *    created: 2020-06-20
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int ans = 0, n = (int) s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            ans++;
        }
    }
    cout << ans << endl;
}