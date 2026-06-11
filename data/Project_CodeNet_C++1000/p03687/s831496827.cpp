#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define l first
#define r second

using namespace std;

const int maxn = 3e5 + 1;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    int l = -1, r = n;
    while (r - l > 1) {
        int md = (l + r) / 2;
        bool gd = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int ck = 0; gd = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == ch)
                    ck = 0;
                else
                    ++ck;
                if (ck > md) {
                    gd = 0;
                    break;
                }
            }
            if (gd) break;
        }
        if (gd) r = md;
        else l = md;
    }
    cout << r;
    return 0;
}
