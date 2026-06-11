#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int f;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'A') {
            f = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s.at(i) == 'Z') {
            cout << i - f + 1 << endl;
            return 0;
        }
    }
    return 0;
}