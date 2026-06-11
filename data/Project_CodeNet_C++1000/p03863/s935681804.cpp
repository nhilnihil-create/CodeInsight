#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == s[n - 1]) {
        if (n & 1) {
            cout << "Second";
        } else {
            cout << "First";
        }
    } else {
        if (n & 1) {
            cout << "First";
        } else {
            cout << "Second";
        }
    }
    return 0;
}
