#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
ll N, A, B;

bool check(ll x, vector<ll> h)
{
    ll cnt = 0;
    rep(i, N)
    {
        ll v = h[i] - x * B;
        if (v <= 0) {
            continue;
        } else {
            cnt += v / A;
            if (v % A) {
                ++cnt;
            }
        }
    }
    return cnt <= x;
}

signed main()
{
    cin >> N >> A >> B;
    vector<ll> h(N);
    A -= B;
    ll ng = 0, ok = 1e9; // ちょうど魔物を倒す回数
    rep(i, N)
    {
        cin >> h[i];
    }
    while (ng + 1 != ok) {
        ll x = (ng + ok) / 2;
        if (check(x, h)) {
            ok = x;
        } else {
            ng = x;
        }
    }
    cout << ok << endl;
    return 0;
}