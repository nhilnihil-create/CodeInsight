/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    vector<bool> seen(26);
    for (char c : s) {
        seen[c - 'a'] = true;
    }
    
    for (int i = 0; i < 26; i++) {
        if (!seen[i]) {
            cout << char('a' + i) << '\n';
            return 0;
        }
    }
    cout << "None" << '\n';
    return 0;
}