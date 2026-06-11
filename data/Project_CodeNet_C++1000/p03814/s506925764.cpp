#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;

    string s;
    cin >> s;

    int l = 0, r = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s.at(i) == 'A') {
            l = i;
            break;
        }
    }

    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (s.at(i) == 'Z') {
            r = i;
            break;
        }
    }

    cout << r - l + 1 << endl;
}