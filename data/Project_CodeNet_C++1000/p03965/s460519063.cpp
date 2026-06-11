#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    int g_cnt = 0;
    rep(i, s.size()) {
        if (s[i] == 'g') {
            if (g_cnt) {
                ans++;
                g_cnt--;
            } else {
                g_cnt++;
            }
        } else {
            if (g_cnt) {
                g_cnt--;
            } else {
                g_cnt++;
                ans--;
            }
        }
    }

    cout << ans << endl;
}