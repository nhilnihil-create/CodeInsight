#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

int main() {
    lint H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(h, H) { cin >> G[h]; }

    map<char, int> mp;
    rep(h, H) rep(w, W) { mp[G[h][w]]++; }

    int set_4 = 0, set_2 = 0, set_1 = 0;
    for (auto p : mp) {
        char c = p.first;
        int x  = p.second;
        set_4 += x / 4;
        x %= 4;
        set_2 += x / 2;
        x %= 2;
        set_1 += x;
    }

    dd(set_4, set_2);
    d(set_1);

    rep(i, H / 2) rep(j, W / 2) {
        if (set_4 == 0) {
            cout << "No" << endl;
            return 0;
        }
        set_4--;
    }
    set_2 += set_4 * 2;

    if (H % 2 == 1) {
        rep(w, W / 2) {
            if (set_2 == 0) {
                cout << "No" << endl;
                return 0;
            }
            set_2--;
        }
    }

    if (W % 2 == 1) {
        rep(h, H / 2) {
            if (set_2 == 0) {
                cout << "No" << endl;
                return 0;
            }
            set_2--;
        }
    }

    set_1 += set_2 * 2;

    if (H % 2 == 1 && W % 2 == 1) {
        if (set_1 == 0) {
            cout << "No" << endl;
            return 0;
        }
        set_1--;
    }

    cout << "Yes" << endl;
}