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
    string s;
    cin >> n >> s;
    
    int begin = 0, bal = 0;
    for (int i = 0; i < n; i++) {
        if (bal <= 0 && s[i] == ')') {
            begin++;
        }
        else if (s[i] == ')') {
            bal--;
        }
        else {
            bal++;
        }
    }
    
    while (begin > 0) {
        cout << '(';
        begin--;
    }
    cout << s;
    while (bal > 0) {
        cout << ')';
        bal--;
    }
    cout << '\n';
    
    return 0;
}