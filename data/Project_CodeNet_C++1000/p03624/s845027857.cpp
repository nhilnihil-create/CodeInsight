#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool exists;
    string ans = "None";
    for (char c = 'a'; c != 'z' + 1; c++) {
        exists = true;
        int i;
        for (i = 0; i < s.size(); i++) {
            if (c == s.at(i)) break;
        }
        if (i == s.size()) {
            ans = c;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
