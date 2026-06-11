#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() < 4) {
        cout << "No" << endl;
    }
    else {
    string y = "YAKI";
    bool ans = true;
    for (int i = 0; i < 4; i++) {
        if (s.at(i) != y.at(i)) {
            ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    }
}