#include <bits/stdc++.h>
using namespace std;

int main() {
    string w;
    cin >> w;

    vector<int> a(26, 0);

    for (char c : w)
        a.at(c - 'a')++;

    bool b = true;
    for (int i : a)
        if (i % 2 == 1) {
            b = false;
            break;
        }

    cout << (b ? "Yes" : "No") << endl;
}