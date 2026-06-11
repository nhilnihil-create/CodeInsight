#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    if (s.size() < 4) {
        cout << "No" << endl;
    } else if (s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
