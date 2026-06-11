#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, d;
    cin >> h >> w >> d;
    string s = "RYGB";
    if (d % 2 == 1) {
        rep(i, 0, h) {
            rep(j, 0, w) cout << s[(i + j) % 4];
            cout << endl;
        }
        return 0;
    }

    vector<vector<int>> ans(d, vector<int>(w + d, -1));
    // while (ans[0].size() < w + d) {
    //     ans[0].emplace_back(tmp);
    //     rep(i, 1, d) {
    //         if (ans[0].size() == w + d) break;
    //         ans[0].emplace_back(tmp + 2);
    //     }
    //     tmp ^= 1;
    // }
    int sp = 0, cnt = 1;
    rep(q, 0, d / 2) {
        int tmp = 0, pos = sp;
        while (pos < w + d) {
            rep(i, 0, cnt) {
                if (0 > pos + i || pos + i >= w + d) continue;
                ans[q][pos + i] = tmp;
            }
            rep(i, cnt, d) {
                if (0 > pos + i || pos + i >= w + d) continue;
                ans[q][pos + i] = tmp + 2;
            }
            tmp ^= 1;
            pos += d;
        }
        cnt += 2;
        sp--;
    }
    rep(q, d / 2, d) {
        rep(i, 0, w) {
            ans[q][i] = 2 ^ ans[q - d / 2][i + d / 2];
        }
    }
    debug(ans);
    int tt = 0;
    rep(i, 0, h) {
        rep(j, 0, w) cout << s[ans[i % d][j] ^ tt];
        cout << endl;
        if (i % d == d - 1) tt ^= 1;
    }
    return 0;
}
