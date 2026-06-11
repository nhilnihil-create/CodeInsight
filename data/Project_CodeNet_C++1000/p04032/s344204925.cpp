#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    rep(i, s.size() - 1) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }

        if (i + 2 < s.size() && s[i] == s[i + 2] && s[i] != s[i + 1]) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}
