#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    if (n == 2) {
        if (s[0] == s[1]) {
            cout << 1 << " " << 2 << endl;
            return 0;
        } else {
            cout << -1 << " " << -1 << endl;
            return 0;
        }

    } else {
        rep(i, n - 1) {
            if (s[i] == s[i + 1]) {
                cout << i + 1 << " " << i + 2 << endl;
                return 0;
            } else if (i < n - 2 && s[i] == s[i + 2]) {
                cout << i + 1 << " " << i + 3 << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
}