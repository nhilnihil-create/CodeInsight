#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;

    char buf[10]{};
    string s;
    cin >> s;
    int idx = 0;
    for (auto ch : s) {
        if (ch == '0') {
            buf[idx++] = ch;
        } else if (ch == '1') {
            buf[idx++] = ch;
        } else if (ch == 'B') {
            if (idx > 0)
                idx--;
        }
    }
    for (int i = 0; i < idx; i++) cout << buf[i];
    cout << endl;
}
