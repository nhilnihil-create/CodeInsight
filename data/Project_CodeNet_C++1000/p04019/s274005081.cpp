#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    map<char, int> m;
    m['N'] = 0;
    m['S'] = 0;
    m['E'] = 0;
    m['W'] = 0;

    for (auto &&c : s) {
        m[c]++;
    }
    if (m['N'] == 0 && m['S'] != 0) {
        cout << "No" << endl;
        return 0;
    }
    if (m['S'] == 0 && m['N'] != 0) {
        cout << "No" << endl;
        return 0;
    }
    if (m['E'] == 0 && m['W'] != 0) {
        cout << "No" << endl;
        return 0;
    }
    if (m['W'] == 0 && m['E'] != 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}