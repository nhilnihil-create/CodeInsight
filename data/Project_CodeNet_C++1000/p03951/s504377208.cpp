#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 2 * n;
    for (int i = n; i < 2 * n; ++i) {
        string ss = s.substr(i - n, 2 * n - i);
        string tt = t.substr(0, 2 * n - i);

        if (ss == tt) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}