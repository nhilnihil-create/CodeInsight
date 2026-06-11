#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n;
    int c4 = 0, c2 = 0, c = 0;
    cin >> n;
    rep(i, 0, n) {
        int x;
        cin >> x;
        if (x % 4 == 0) {++c4; continue;}
        if (x % 2 == 0) {++c2; continue;}
        ++c;
    }
    int d = min(c4, c);
    c4 -= d;
    c -= d;
    if (c > 1) {cout << "No\n"; return 0;}
    if (c == 1 && c2 > 0) {cout << "No\n"; return 0;}
    cout << "Yes\n";
}