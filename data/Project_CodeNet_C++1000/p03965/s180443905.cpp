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
    int n = (int) s.length(), p_cnt = 0;
    for (char c : s) {
        if (c == 'p') p_cnt++;
    }
    cout << n / 2 - p_cnt << endl;
}