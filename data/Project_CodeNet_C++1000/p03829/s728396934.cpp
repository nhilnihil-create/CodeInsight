#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;

signed main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    ll ans = 0ll;
    rep(i, N)
    {
        cin >> X[i];
    }
    rep(i, N - 1)
    {
        ans += min(A * (X[i + 1] - X[i]), B);
    }
    cout << ans << endl;
    return 0;
}