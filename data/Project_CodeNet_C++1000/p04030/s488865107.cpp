#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans;
    rep(i, s.size()) {
        if (s[i] == 'B') {
            if (ans.empty()) continue;
            ans = ans.substr(0, ans.size() - 1);
        } else
            ans += s[i];
    }

    cout << ans << endl;
    return 0;
}
