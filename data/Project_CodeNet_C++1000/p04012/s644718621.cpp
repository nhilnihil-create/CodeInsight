#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    map<char, int> m;
    for (auto &&c : s) {
        m[c]++;
    }
    for (auto &&i : m) {
        if (i.second % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}