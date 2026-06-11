#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    string* s = &a;
    while (!(*s).empty()) {
        auto ch = (*s)[0];
        (*s).erase(0, 1);
        if (ch == 'a') {
            s = &a;
        } else if (ch == 'b') {
            s = &b;
        } else {
            s = &c;
        }
    }
    cout << (s == &a ? 'A' : (s == &b ? 'B': 'C')) << endl;
    return 0;
}
