#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool a = false, b = false, c = false, d = false;
    for (char x : s) {
        a |= (x == 'N');
        b |= (x == 'E');
        c |= (x == 'W');
        d |= (x == 'S');
    }
    cout << ((a != d || b != c) ? "No" : "Yes") << '\n';
    return 0;
}
