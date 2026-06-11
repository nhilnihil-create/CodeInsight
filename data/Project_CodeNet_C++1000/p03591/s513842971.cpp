// https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_a
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    puts(regex_search(s, regex("^YAKI.*")) ? "Yes" : "No");

    return 0;
}
