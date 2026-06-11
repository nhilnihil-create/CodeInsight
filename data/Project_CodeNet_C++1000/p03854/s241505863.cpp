/**
 *    author:  FromDihPout
 *    created: 2020-06-21
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s;
    int n = (int) s.length(), index = n;
    vector<string> words = {"eraser", "dreamer", "erase", "dream"};
    while (index > 0) {
        bool ok = false;
        for (string w : words) {
            int len = (int) w.length();
            if (index - len < 0) continue;
            if (s.substr(index - len, w.length()) == w) {
                ok = true;
                index -= w.length();
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}