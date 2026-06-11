#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> set;

    bool b = false;
    for (char c : s) {
        if (set.find(c) == set.end())
            set.insert(c);
        else {
            b = true;
            break;
        }
    }

    cout << (b ? "no" : "yes") << endl;
}