#include <bits/stdc++.h>
using namespace std;


void solve () {
    string s;
    cin >> s;
    vector<string> a = {"dreamer", "dream", "erase", "eraser"};
    int i = (int) s.size() - 1;
    while (i >= 0) {
        bool okk = 0;
        for (auto t : a) {
            int sz = (int) t.size() - 1;
            bool ok = 1;
            for (int j = i, k = sz; k >= 0; j--, k--) {
                if (s[j] != t[k]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                i -= sz + 1;
                okk = 1;
                break;
            }
        }
        if(!okk) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
