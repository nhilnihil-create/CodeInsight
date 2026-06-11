#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int win = 0, lose = 0;
    int p = 0, r = 0;
    r++;
    if (s[0] == 'p') {
        lose++;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == 'g') {
            if (p < r) {
                p++;
                win++;
            } else {
                r++;
            }
        } else {
            if (p < r) {
                p++;
            } else {
                r++;
                lose++;
            }
        }
    }
    cout << win - lose;
    return 0;
}
