/**
 *    author:  FromDihPout
 *    created: 2020-06-21
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int) s.length();
    if ((n % 2 == 0) ^ (s[0] == s[n - 1])) {
        cout << "Second" << endl;
    }
    else {
        cout << "First" << endl;
    }
    return 0;
}