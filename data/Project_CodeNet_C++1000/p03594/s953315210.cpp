#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 19;
const int MOD = (int)1e9 + 7;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m, d;
    while (cin >> n >> m >> d) {
        string Z = "RGYB";
        vector<vector<char> > ans(n, vector<char>(m));

        if (d % 2 == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = Z[(i + j) % 2];
                }
            }
        } else {
            auto ok = [&](int x, int y) {
                return 0 <= x && x < n && 0 <= y && y < m;
            };

            auto g = [&](int x, int y, int c) {
                if (!ok(x, y)) return false;
                ans[x][y] = Z[c];
                return true;
            };

            set<pair<int, int> > st;
            function<void(int, int, int)> paint = [&](int x, int y, int c) {
                if (st.find({x, y}) != st.end()) return;
                st.insert({x, y});
                bool f = 0;
                for (int i = 0; i < d / 2; i++) {
                    for (int j = 0; j < d / 2; j++) {
                        f |= g(x + i + j, y + i - j, c);
                    }
                }
                if (!f) return;
                paint(x + d / 2, y + d / 2, c ^ 1);
                paint(x - d / 2, y - d / 2, c ^ 1);
                paint(x + d / 2, y - d / 2, c ^ 2);
                paint(x - d / 2, y + d / 2, c ^ 2);
            };

            paint(0, 0, 0);
            paint(0, 1, 0);
        }

        for (int i = 0; i < n; i++) {
            string s = "";
            for (char c : ans[i]) s += c;
            cout << s << endl;
        }
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}