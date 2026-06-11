// https://atcoder.jp/contests/abc062/tasks/arc074_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
const ll INFL = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n * 3);
    REP(i, n * 3) cin >> v[i];
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;
    ll sum1 = 0, sum2 = 0;
    REP(i, n) {
        q1.push(v[i]);
        q2.push(v[i + n * 2]);
        sum1 += v[i];
        sum2 += v[i + n * 2];
    }
    vector<ll> v1, v2;
    v1.push_back(sum1);
    v2.push_back(sum2);
    REP(i, n) {
        int t = q1.top();
        if (t < v[i + n]) {
            q1.pop();
            q1.push(v[i + n]);
            sum1 += v[i + n] - t;
        }
        v1.push_back(sum1);
    }
    REP(i, n) {
        int t = q2.top();
        if (t > v[2 * n - i - 1]) {
            q2.pop();
            q2.push(v[2 * n - i - 1]);
            sum2 += v[2 * n - i - 1] - t;
        }
        v2.push_back(sum2);
    }
    ll maxv = -INFL;
    ll minv = INFL;
    ll ans = -INFL;
    for (auto &x : v1) {
        maxv = max(maxv, x);
        x = maxv;
    }
    for (auto &x : v2) {
        minv = min(minv, x);
        x = minv;
    }
    REP(i, v1.size()) ans = max(ans, v1[i] - v2[v2.size() - 1 - i]);
    cout << ans << endl;

    return 0;
}
