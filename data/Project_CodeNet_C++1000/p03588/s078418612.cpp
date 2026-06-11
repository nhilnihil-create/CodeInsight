// https://atcoder.jp/contests/tenka1-2017-beginner/tasks/tenka1_2017_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    REP(i, n) cin >> v[i].first >> v[i].second;
    sort(ALLR(v));
    cout << v[0].first + v[0].second << endl;
    return 0;
}
