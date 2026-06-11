#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
int N, T;

signed main()
{
    cin >> N >> T;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    int minv = A[0], maxv = -INF, cnt = 0;
    for (int i = 1; i < N; ++i) {
        int cur = A[i];
        minv = min(minv, cur);
        if (cur - minv > maxv) {
            maxv = cur - minv;
            cnt = 1;
        } else if (cur - minv == maxv) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
