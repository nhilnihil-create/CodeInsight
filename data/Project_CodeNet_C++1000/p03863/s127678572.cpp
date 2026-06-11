#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = (int)s.size();
    
    bool is_same = true;
    for (int i = 2; i < len; i++) {
        if (s.at(i) != s.at(i - 2)) {
            is_same = false;
            break;
        }
    }
    if (is_same) {
        cout << "Second" << endl;
        return 0;
    }

    if ((s.at(0) == s.at(len - 1) && len % 2 == 0) || (s.at(0) != s.at(len - 1) && len % 2 == 1)) cout << "First" << endl;
    else cout << "Second" << endl;
}   