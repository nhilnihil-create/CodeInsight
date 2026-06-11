#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<bool> b(26, false);
    for (char c : s)
        b.at(c - 'a') = true;

    bool o = false;
    for (int i = 0; i < 26; i++)
        if (!b.at(i)) {
            cout << (char) ('a' + i) << endl;
            o = true;
            break;
        }

    if (!o)
        cout << "None" << endl;
}