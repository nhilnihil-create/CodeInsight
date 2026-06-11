// https://atcoder.jp/contests/arc069/tasks/arc069_b
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
const int MAXN = 1e5 + 4;
int n;
char s[MAXN];
int a[MAXN];

int main() {
    cin >> n;
    cin >> s;
    s[n] = s[0], s[n + 1] = s[1];
    REP(i, 4) {
        a[0] = i & 1, a[1] = (i >> 1) & 1;
        FOR(j, 2, n + 2) a[j] = (s[j - 1] == 'x') ^ a[j - 1] ^ a[j - 2];
        if (a[0] == a[n] && a[1] == a[n + 1]) {
            REP(j, n) { cout << (a[j] ? "W" : "S"); }
            cout << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
