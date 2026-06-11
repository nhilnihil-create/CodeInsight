#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string s; cin >> s;
    int n = s.length();

    int ans = INF;
    for (int i = 0; i < 26; ++i) {
        char t = 'a' + i;

        int l = 0;
        int mx = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == t) {
                l = 0;
            } else {
                ++l;
            }

            mx = max(mx, l);
        }

        ans = min(ans, mx);
    }

    cout << ans << endl;
}