#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 19;

bool ok (string &s) {
    set < char > cs;
    for (char c: s)
        cs.insert(c);
    return bool(int(cs.size()) == 1);
}

signed main () {
    string t;
    cin >> t;
    int ans = inf;
    for (char here = 'a'; here <= 'z'; ++here) {
        int now = 0;
        string s = t;
        while (!ok(s)) {
            string cur(int(s.size()) - 1, '0');
            map < char, int > cnt;
            for (int i = 0; i < int(s.size()) - 1; ++i) 
                ++cnt[s[i]];
            for (int i = 0; i < int(s.size()) - 1; ++i) {
                if (s[i] == here || s[i + 1] == here)
                    cur[i] = here;
                else if (rand() & 1)
                    cur[i] = s[i];
                else
                    cur[i] = s[i + 1];
            }
            s = cur;
            ++now;
        }
        ans = min(ans, now);
    }
    cout << ans << '\n';
}
