// https://atcoder.jp/contests/abc062/tasks/abc062_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0) {
        cout << "0\n";
    } else {
        int minv = 1e9;
        REP(e, 2) {
            int h1 = h / 3;
            int w1 = w / 2;
            vector<int> s(3);
            REP(i, 2) REP(j, 2) {
                s[0] = (h1 + i) * w;
                s[1] = (h - h1 - i) * (w1 + j);
                s[2] = (h - h1 - i) * (w - w1 - j);
                sort(ALL(s));
                minv = min(minv, abs(s[0] - s[2]));
            }
            swap(h, w);
        }
        if (w % 3 != 0) {
            minv = min(minv, h);
        }
        if (h % 3 != 0) {
            minv = min(minv, w);
        }

        cout << minv << "\n";
    }

    return 0;
}
