#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

priority_queue<int, vector<int>, greater<int>> qmaxv;
priority_queue<int> qminv;
const int INF = 1e6;
ll max_sum[INF + 1], min_sum[INF + 1], maxv = 0, minv = 0;
ll a[INF], ans = -1e16;

int main()
{
    int n;
    cin >> n;

    rep(i, 3 * n) cin >> a[i];

    rep(i, n)
    {
        qmaxv.push(a[i]);
        qminv.push(a[2 * n + i]);
        maxv += a[i];
        minv += a[2 * n + i];
    }
    max_sum[0] = maxv, min_sum[n] = minv;
    rep(i, n)
    {
        qmaxv.push(a[n + i]);
        maxv = maxv + a[n + i] - qmaxv.top();
        max_sum[i + 1] = maxv;
        qmaxv.pop();
        qminv.push(a[2 * n - 1 - i]);
        minv = minv + a[2 * n - 1 - i] - qminv.top();
        min_sum[n - 1 - i] = minv;
        qminv.pop();
    }

    rep(i, n + 1) ans = max(ans, max_sum[i] - min_sum[i]);

    OP(ans);

    return 0;
}