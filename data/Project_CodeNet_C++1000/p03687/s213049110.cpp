#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
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
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int main() {
    string S;
    cin >> S;

    set<char> se{};
    for (int i = 0; i < S.size(); i++) {
        se.insert(S[i]);
    }

    int mi = 1e9;
    for (const auto c : se) {
        d(c);

        bool ok = true;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != c) { ok = false; }
        }
        if (ok) {
            mi = min(mi, 0);
            continue;
        }

        string prev = S;
        for (int t = 0; t < S.size() - 1; t++) {
            string next = prev;
            for (int i = 0; i < prev.size(); i++) {
                if (prev[i] == c) { next[i] = next[max(0, i - 1)] = c; }
            }
            next = next.substr(0, next.size() - 1);

            bool ok = true;
            for (int i = 0; i < next.size(); i++) {
                if (next[i] != c) { ok = false; }
            }

            if (ok) {
                mi = min(mi, t + 1);
                break;
            }

            prev = next;
        }
    }

    cout << mi << endl;
    return 0;
}