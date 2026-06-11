#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string s; cin >> s;

    int ans = 0;
    int g_cnt = 0;
    int p_cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i == 0) {
            g_cnt++;
            if (s[i] == 'p') ans--;
        } else {
            if (s[i] == 'g') {
                if (p_cnt < g_cnt) {
                    p_cnt++;
                    ans++;
                } else {
                    g_cnt++;
                }
            } else {
                if (p_cnt < g_cnt) {
                    p_cnt++;
                } else {
                    g_cnt++;
                    ans--;
                }
            }
        }
    }

    cout << ans << endl;
}